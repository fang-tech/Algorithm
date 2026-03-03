#!/usr/bin/env python3
"""
Scan the resolved/ directory for Java algorithm files and generate solutions.md
with each problem's relative path and its one-line solution hint.

One-line hint extraction strategy (in order):
  1. First /** ... */ block in the @lc code section that is NOT boilerplate
     (e.g., not a "Definition for singly-linked list" or "Your XYZ object..." block).
  2. Fallback: descriptive lines in the top file-level /* */ comment that appear
     after the "[id] Problem Title" line.
"""

import os
import re


def extract_oneliner(content: str) -> str:
    # ── Step 1: look inside the @lc code section ──────────────────────────────
    code_start = content.find("// @lc code=start")
    code_end   = content.find("// @lc code=end")
    code_section = content[code_start:code_end] if code_start != -1 else content

    javadoc_re = re.compile(r"/\*\*(.*?)\*/", re.DOTALL)
    for m in javadoc_re.finditer(code_section):
        block = m.group(1)
        # Skip common boilerplate blocks
        if "Definition for" in block or "Your " in block:
            continue
        lines = [
            line.strip().lstrip("*").strip()
            for line in block.splitlines()
        ]
        lines = [l for l in lines if l]
        if lines:
            return " ".join(lines)

    # ── Step 2: fallback – top file comment after [id] Title line ─────────────
    top_comment = re.search(r"/\*(.*?)\*/", content, re.DOTALL)
    if top_comment:
        block = top_comment.group(1)
        lines = []
        found_title = False
        for raw in block.splitlines():
            line = raw.strip().lstrip("*").strip()
            if not found_title:
                if re.match(r"\[\d+\]", line):
                    found_title = True
                continue
            if not line or line.startswith("@"):
                continue
            lines.append(line)
        if lines:
            return " ".join(lines)

    return ""


def file_display_name(filename: str) -> str:
    """'206.反转链表.java' → '206.反转链表'"""
    return filename[:-5] if filename.endswith(".java") else filename


def scan_resolved(base_dir: str):
    """Return {category: [(display_name, full_abs_path, hint), ...]}"""
    resolved_dir = os.path.join(base_dir, "resolved")
    categories: dict[str, list] = {}
    for root, dirs, files in os.walk(resolved_dir):
        dirs.sort()
        category = os.path.relpath(root, resolved_dir)
        if category == ".":
            category = "其他"
        for filename in sorted(files):
            if not filename.endswith(".java"):
                continue
            full_path = os.path.join(root, filename)
            with open(full_path, "r", encoding="utf-8") as f:
                content = f.read()
            hint = extract_oneliner(content)
            display = file_display_name(filename)
            categories.setdefault(category, []).append((display, full_path, hint))
    return categories


def generate_md(categories: dict, output_path: str, base_dir: str):
    lines = ["# Algorithm Solutions\n"]
    for category, items in sorted(categories.items()):
        lines.append(f"## {category}\n")
        lines.append("| 题目 | 一句话题解 |")
        lines.append("| --- | --- |")
        for display, full_path, hint in items:
            rel = os.path.relpath(full_path, base_dir)
            link = f"[{display}]({rel})"
            lines.append(f"| {link} | {hint} |")
        lines.append("")

    with open(output_path, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    print(f"Generated: {output_path}")


if __name__ == "__main__":
    base_dir   = os.path.dirname(os.path.abspath(__file__))
    categories = scan_resolved(base_dir)
    output     = os.path.join(base_dir, "README.md")
    generate_md(categories, output, base_dir)
