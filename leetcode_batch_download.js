#!/usr/bin/env node

"use strict";

const childProcess = require("child_process");
const fs = require("fs");
const os = require("os");
const path = require("path");

const SUPPORTED_LANGUAGES = new Set([
    "bash", "c", "cpp", "csharp", "golang", "java", "javascript", "kotlin",
    "mysql", "php", "python", "python3", "ruby", "rust", "scala", "swift", "typescript",
]);

const LANGUAGE_EXTENSIONS = {
    bash: ".sh",
    c: ".c",
    cpp: ".cpp",
    csharp: ".cs",
    golang: ".go",
    java: ".java",
    javascript: ".js",
    kotlin: ".kt",
    mysql: ".sql",
    php: ".php",
    python: ".py",
    python3: ".py",
    ruby: ".rb",
    rust: ".rs",
    scala: ".scala",
    swift: ".swift",
    typescript: ".ts",
};

function printHelp() {
    console.log(`Usage:
  node leetcode_batch_download.js <problem...> [options]

Problem formats:
  1 15 42             Individual problem IDs or slugs
  1-20                Inclusive integer range
  --file problems.txt Read IDs, slugs, and ranges from a file
  --file problems.md  Resolve a copied LeetCode list by Chinese title

Options:
  --lang <language>   Override VS Code's leetcode.defaultLanguage
  --out <directory>   Override VS Code's leetcode.workspaceFolder
  --description       Include the full description as source comments
  --no-description    Only generate the source template
  --english           Disable endpoint translation
  --delay <ms>        Delay between downloads (default: 350)
  --force             Fetch again; the CLI creates a suffixed file safely
  --dry-run           Print the resolved plan without downloading
  -h, --help          Show this help

Examples:
  node leetcode_batch_download.js 1-20 42 146
  node leetcode_batch_download.js --file problems.md
  node leetcode_batch_download.js 1-10 --lang java --out ./problems
`);
}

function fail(message) {
    console.error(`Error: ${message}`);
    process.exitCode = 1;
}

function valueAfter(args, index, option) {
    const value = args[index + 1];
    if (!value || value.startsWith("--")) {
        throw new Error(`${option} requires a value`);
    }
    return value;
}

function parseArguments(argv) {
    const options = {
        problems: [],
        inputFiles: [],
        language: undefined,
        outDir: undefined,
        description: undefined,
        english: false,
        delay: 350,
        force: false,
        dryRun: false,
    };

    for (let index = 0; index < argv.length; index += 1) {
        const arg = argv[index];
        switch (arg) {
            case "-h":
            case "--help":
                options.help = true;
                break;
            case "--file":
                options.inputFiles.push(valueAfter(argv, index, arg));
                index += 1;
                break;
            case "--lang":
                options.language = valueAfter(argv, index, arg);
                index += 1;
                break;
            case "--out":
                options.outDir = valueAfter(argv, index, arg);
                index += 1;
                break;
            case "--delay":
                options.delay = Number(valueAfter(argv, index, arg));
                index += 1;
                break;
            case "--description":
                options.description = true;
                break;
            case "--no-description":
                options.description = false;
                break;
            case "--english":
                options.english = true;
                break;
            case "--force":
                options.force = true;
                break;
            case "--dry-run":
                options.dryRun = true;
                break;
            default:
                if (arg.startsWith("-")) {
                    throw new Error(`unknown option: ${arg}`);
                }
                options.problems.push(arg);
        }
    }

    if (!Number.isFinite(options.delay) || options.delay < 0) {
        throw new Error("--delay must be a non-negative number");
    }
    if (options.language && !SUPPORTED_LANGUAGES.has(options.language)) {
        throw new Error(`unsupported language: ${options.language}`);
    }
    return options;
}

function vscodeSettingsPath() {
    if (process.platform === "darwin") {
        return path.join(os.homedir(), "Library", "Application Support", "Code", "User", "settings.json");
    }
    if (process.platform === "win32") {
        return path.join(process.env.APPDATA || "", "Code", "User", "settings.json");
    }
    return path.join(process.env.XDG_CONFIG_HOME || path.join(os.homedir(), ".config"), "Code", "User", "settings.json");
}

function readVscodeSettings() {
    const settingsPath = process.env.VSCODE_SETTINGS || vscodeSettingsPath();
    let source = "";
    try {
        source = fs.readFileSync(settingsPath, "utf8");
    } catch (error) {
        if (error.code !== "ENOENT") {
            throw error;
        }
    }

    const stringSetting = (name) => {
        const match = source.match(new RegExp(`"${name.replace(/\./g, "\\.")}"\\s*:\\s*"([^"]*)"`));
        return match ? match[1] : undefined;
    };
    const booleanSetting = (name) => {
        const match = source.match(new RegExp(`"${name.replace(/\./g, "\\.")}"\\s*:\\s*(true|false)`));
        return match ? match[1] === "true" : undefined;
    };

    const showDescription = stringSetting("leetcode.showDescription");
    const descriptionInFile = showDescription
        ? showDescription === "In File Comment" || showDescription === "Both"
        : booleanSetting("leetcode.showCommentDescription") || false;

    return {
        language: stringSetting("leetcode.defaultLanguage"),
        outDir: stringSetting("leetcode.workspaceFolder"),
        descriptionInFile,
        settingsPath,
    };
}

function locateCli() {
    if (process.env.LEETCODE_CLI) {
        return path.resolve(process.env.LEETCODE_CLI);
    }

    const located = childProcess.spawnSync("code", ["--locate-extension", "leetcode.vscode-leetcode"], {
        encoding: "utf8",
    });
    if (located.status === 0 && located.stdout.trim()) {
        const candidate = path.join(located.stdout.trim(), "node_modules", "vsc-leetcode-cli", "bin", "leetcode");
        if (fs.existsSync(candidate)) {
            return candidate;
        }
    }

    const extensionRoot = path.join(os.homedir(), ".vscode", "extensions");
    if (fs.existsSync(extensionRoot)) {
        const installed = fs.readdirSync(extensionRoot)
            .filter((name) => name.startsWith("leetcode.vscode-leetcode-"))
            .sort()
            .reverse();
        for (const directory of installed) {
            const candidate = path.join(extensionRoot, directory, "node_modules", "vsc-leetcode-cli", "bin", "leetcode");
            if (fs.existsSync(candidate)) {
                return candidate;
            }
        }
    }
    throw new Error("cannot find the LeetCode VS Code extension CLI; install/enable leetcode.vscode-leetcode or set LEETCODE_CLI");
}

function tokenize(source) {
    return source
        .split(/\r?\n/)
        .map((line) => line.replace(/#.*$/, ""))
        .join(" ")
        .split(/[\s,]+/)
        .filter(Boolean);
}

function expandProblems(tokens) {
    const expanded = [];
    for (const token of tokens) {
        const range = token.match(/^(\d+)-(\d+)$/);
        if (!range) {
            expanded.push(token);
            continue;
        }
        const start = Number(range[1]);
        const end = Number(range[2]);
        const step = start <= end ? 1 : -1;
        for (let id = start; id !== end + step; id += step) {
            expanded.push(String(id));
        }
    }
    return Array.from(new Set(expanded));
}

function collectProblems(options) {
    const plan = expandProblems(tokenize(options.problems.join(" "))).map((problem) => ({ problem }));
    for (const filename of options.inputFiles) {
        const source = fs.readFileSync(path.resolve(filename), "utf8");
        const categorizedTitles = titlesBeforeDifficulty(source);
        if (categorizedTitles.length > 0) {
            plan.push(...resolveTitles(categorizedTitles));
        } else {
            plan.push(...expandProblems(tokenize(source)).map((problem) => ({ problem })));
        }
    }
    const seen = new Set();
    return plan.filter((entry) => {
        if (seen.has(entry.problem)) {
            return false;
        }
        seen.add(entry.problem);
        return true;
    });
}

function titlesBeforeDifficulty(source) {
    const lines = source.split(/\r?\n/).map((line) => line.trim()).filter(Boolean);
    const entries = [];
    let category;
    let previousDifficulty = -1;
    for (let index = 1; index < lines.length; index += 1) {
        if (/^(简单|中等|困难|Easy|Medium|Hard)$/i.test(lines[index])) {
            const titleIndex = index - 1;
            if (titleIndex - previousDifficulty > 1) {
                category = lines[titleIndex - 1];
            }
            entries.push({ title: lines[titleIndex], category });
            previousDifficulty = index;
        }
    }
    return entries;
}

function normalizeTitle(title) {
    return title.normalize("NFKC").replace(/\s+/g, "").toLowerCase();
}

function problemCaches() {
    const lcRoot = path.join(os.homedir(), ".lc");
    if (!fs.existsSync(lcRoot)) {
        return [];
    }
    return fs.readdirSync(lcRoot, { withFileTypes: true })
        .filter((entry) => entry.isDirectory())
        .map((entry) => path.join(lcRoot, entry.name, "cache", "problems.json"))
        .filter((filename) => fs.existsSync(filename));
}

function resolveTitles(entries) {
    const cacheFiles = problemCaches();
    if (cacheFiles.length === 0) {
        throw new Error("cannot resolve problem titles because the extension problem cache is missing; refresh LeetCode Explorer first");
    }

    const byTitle = new Map();
    for (const filename of cacheFiles) {
        const problems = JSON.parse(fs.readFileSync(filename, "utf8"));
        for (const problem of problems) {
            const key = normalizeTitle(problem.name);
            const candidates = byTitle.get(key) || [];
            if (!candidates.some((candidate) => candidate.fid === problem.fid)) {
                candidates.push(problem);
            }
            byTitle.set(key, candidates);
        }
    }

    const unresolved = [];
    const categories = [];
    const resolved = entries.map((entry) => {
        const candidates = byTitle.get(normalizeTitle(entry.title)) || [];
        const canonical = candidates.find((problem) => /^\d+$/.test(problem.fid) && problem.category === "algorithms")
            || candidates.find((problem) => /^\d+$/.test(problem.fid))
            || candidates[0];
        if (!canonical) {
            unresolved.push(entry.title);
            return undefined;
        }
        if (!categories.includes(entry.category)) {
            categories.push(entry.category);
        }
        const categoryIndex = categories.indexOf(entry.category) + 1;
        const folder = path.join("hot100", `${String(categoryIndex).padStart(2, "0")}-${safeFolderName(entry.category)}`);
        return { problem: canonical.fid, folder };
    }).filter(Boolean);

    if (unresolved.length > 0) {
        throw new Error(`cannot resolve ${unresolved.length} problem title(s): ${unresolved.join(", ")}`);
    }
    console.log(`Resolved:    ${resolved.length} problem titles from ${cacheFiles.length} extension cache file(s)`);
    console.log(`Folders:     ${categories.length} categories under hot100/`);
    return resolved;
}

function safeFolderName(name) {
    return name.replace(/[\\/:*?"<>|]/g, "-").replace(/\.+$/, "").trim();
}

function existingProblemIds(outDir, language) {
    const ids = new Set();
    const extension = LANGUAGE_EXTENSIONS[language];
    if (!extension || !fs.existsSync(outDir)) {
        return ids;
    }

    for (const entry of fs.readdirSync(outDir, { withFileTypes: true })) {
        if (!entry.isFile() || path.extname(entry.name) !== extension) {
            continue;
        }
        try {
            const fd = fs.openSync(path.join(outDir, entry.name), "r");
            const buffer = Buffer.alloc(512);
            const length = fs.readSync(fd, buffer, 0, buffer.length, 0);
            fs.closeSync(fd);
            const match = buffer.toString("utf8", 0, length).match(/@lc\s+app=\S+\s+id=([^\s]+)\s+lang=([^\s]+)/);
            if (match && match[2] === language) {
                ids.add(match[1]);
            }
        } catch (_) {
            // An unreadable unrelated file should not block the batch.
        }
    }
    return ids;
}

function topLevelProblemFiles(outDir, language) {
    const files = new Map();
    const extension = LANGUAGE_EXTENSIONS[language];
    if (!extension || !fs.existsSync(outDir)) {
        return files;
    }
    for (const entry of fs.readdirSync(outDir, { withFileTypes: true })) {
        if (!entry.isFile() || path.extname(entry.name) !== extension) {
            continue;
        }
        const filename = path.join(outDir, entry.name);
        try {
            const source = fs.readFileSync(filename, "utf8").slice(0, 512);
            const match = source.match(/@lc\s+app=\S+\s+id=([^\s]+)\s+lang=([^\s]+)/);
            if (match && match[2] === language) {
                files.set(match[1], filename);
            }
        } catch (_) {
            // An unreadable unrelated file should not block organization.
        }
    }
    return files;
}

function organizeExistingFiles(plan, outDir, language) {
    const topLevelFiles = topLevelProblemFiles(outDir, language);
    let moved = 0;
    for (const entry of plan) {
        if (!entry.folder || !topLevelFiles.has(entry.problem)) {
            continue;
        }
        const source = topLevelFiles.get(entry.problem);
        const targetDir = path.join(outDir, entry.folder);
        const target = path.join(targetDir, path.basename(source));
        fs.mkdirSync(targetDir, { recursive: true });
        if (fs.existsSync(target)) {
            continue;
        }
        fs.renameSync(source, target);
        moved += 1;
    }
    if (moved > 0) {
        console.log(`Organized:   ${moved} existing problem files`);
    }
}

function sleep(milliseconds) {
    if (milliseconds <= 0) {
        return;
    }
    const shared = new Int32Array(new SharedArrayBuffer(4));
    Atomics.wait(shared, 0, 0, milliseconds);
}

function compactError(result) {
    return `${result.stdout || ""}\n${result.stderr || ""}`
        .split(/\r?\n/)
        .filter((line) => line
            && !line.startsWith("(node:")
            && !line.startsWith("(Use `node")
            && !line.includes("DeprecationWarning"))
        .slice(-8)
        .join("\n");
}

function verifyLogin(cli) {
    const result = childProcess.spawnSync(process.execPath, [cli, "user"], {
        encoding: "utf8",
        maxBuffer: 10 * 1024 * 1024,
    });
    const output = `${result.stdout || ""}\n${result.stderr || ""}`;
    if (result.status !== 0 || /not\s+(logged|login)|please\s+login|\[ERROR\]/i.test(output)) {
        throw new Error(`the extension CLI is not logged in\n${compactError(result)}`);
    }
    return result.stdout.split(/\r?\n/).find((line) => /https?:\/\//.test(line)) || "authenticated session found";
}

function main() {
    let options;
    try {
        options = parseArguments(process.argv.slice(2));
    } catch (error) {
        fail(error.message);
        printHelp();
        return;
    }
    if (options.help) {
        printHelp();
        return;
    }

    try {
        const settings = readVscodeSettings();
        const language = options.language || settings.language || "cpp";
        const outDir = path.resolve(options.outDir || settings.outDir || path.join(os.homedir(), ".leetcode"));
        const withDescription = options.description === undefined ? settings.descriptionInFile : options.description;
        const plan = collectProblems(options);
        const cli = locateCli();

        if (!SUPPORTED_LANGUAGES.has(language)) {
            throw new Error(`unsupported language from VS Code settings: ${language}`);
        }
        if (plan.length === 0) {
            throw new Error("no problems supplied; pass IDs/ranges or use --file");
        }

        console.log(`CLI:         ${cli}`);
        console.log(`Language:    ${language}`);
        console.log(`Output:      ${outDir}`);
        console.log(`Description: ${withDescription ? "included" : "template only"}`);
        console.log(`Problems:    ${plan.length} (${plan.map((entry) => entry.problem).join(", ")})`);

        if (options.dryRun) {
            console.log("Dry run complete; no network requests were made.");
            return;
        }

        console.log(`Account:     ${verifyLogin(cli).trim()}`);
        fs.mkdirSync(outDir, { recursive: true });
        organizeExistingFiles(plan, outDir, language);
        const failures = [];
        let downloaded = 0;
        let skipped = 0;

        plan.forEach((entry, index) => {
            const problem = entry.problem;
            const targetDir = entry.folder ? path.join(outDir, entry.folder) : outDir;
            const existing = existingProblemIds(targetDir, language);
            if (!options.force && existing.has(problem)) {
                skipped += 1;
                console.log(`[${index + 1}/${plan.length}] skip ${problem} (already exists)`);
                return;
            }

            console.log(`[${index + 1}/${plan.length}] fetch ${problem}`);
            fs.mkdirSync(targetDir, { recursive: true });
            const args = [cli, "show", problem, "-g", "-l", language, "-o", targetDir];
            if (withDescription) {
                args.push("-x");
            }
            if (options.english) {
                args.push("-T");
            }
            const result = childProcess.spawnSync(process.execPath, args, {
                encoding: "utf8",
                maxBuffer: 20 * 1024 * 1024,
            });
            const output = `${result.stdout || ""}\n${result.stderr || ""}`;
            if (result.status !== 0 || /\[ERROR\]/.test(output) || !/Source Code:/.test(output)) {
                failures.push({ problem, detail: compactError(result) || "the CLI did not report a generated source file" });
                console.error(`  failed: ${failures[failures.length - 1].detail.split(/\r?\n/)[0]}`);
            } else {
                downloaded += 1;
                const sourceLine = result.stdout.split(/\r?\n/).find((line) => line.includes("Source Code:"));
                console.log(`  saved: ${sourceLine ? sourceLine.split("Source Code:")[1].trim() : problem}`);
            }

            if (index < plan.length - 1) {
                sleep(options.delay);
            }
        });

        console.log(`Done: ${downloaded} downloaded, ${skipped} skipped, ${failures.length} failed.`);
        if (failures.length > 0) {
            for (const failure of failures) {
                console.error(`- ${failure.problem}: ${failure.detail}`);
            }
            process.exitCode = 1;
        }
    } catch (error) {
        fail(error.message);
    }
}

main();
