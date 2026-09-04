# 批量拉取 LeetCode 题目

本仓库的批量脚本直接调用已安装的 `LeetCode.vscode-leetcode` 扩展所附带的
`vsc-leetcode-cli`，因此会复用扩展当前的登录状态和中英文站点，不需要再次保存 Cookie。

## 使用

```bash
# 连续题号和零散题号可以混用
node leetcode_batch_download.js 1-20 42 146

# 在源码注释中包含完整题目描述
node leetcode_batch_download.js 1-20 --description

# 指定语言和保存目录
node leetcode_batch_download.js 1-20 --lang java --out ./problems
```

题目较多时可放入清单文件。空白、逗号和换行均可作为分隔符，`#` 后为注释：

```text
# arrays
1-10
15, 42
two-sum
```

```bash
node leetcode_batch_download.js --file problems.txt
```

也可以直接使用从 LeetCode 题单页面复制得到的文本或 Markdown。脚本会提取难度标记
（`简单`、`中等`、`困难`）前面的题名，并通过扩展本地题库缓存解析为正式题号；同名的 LCR 题目会优先解析为常规题目：

```bash
node leetcode_batch_download.js --file problems.md --dry-run
node leetcode_batch_download.js --file problems.md
```

带分类的题单会保存到 `hot100/01-分类名/`、`hot100/02-分类名/` 等目录。数字前缀让文件夹在资源管理器中保持题单顺序；再次运行时，脚本也会将输出目录顶层已有的同题模板迁移到对应分类。

脚本默认读取 VS Code 用户配置中的 `leetcode.defaultLanguage`、
`leetcode.workspaceFolder` 和题目描述设置。可先用 `--dry-run` 检查展开后的题目清单和输出目录；
成功生成过的同语言题目会自动跳过。`--force` 会让 CLI 另建带序号后缀的文件，不会覆盖已有解答。

默认逐题串行拉取并间隔 350ms，某道题失败不会阻断剩余任务，最终会汇总失败项并返回非零退出码。
可用 `--delay 1000` 调低请求频率，用 `--english` 强制拉取英文题面。
