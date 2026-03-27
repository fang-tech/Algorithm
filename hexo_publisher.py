import os
import re
import subprocess
from datetime import datetime

def get_git_creation_date(filepath: str) -> str:
    """获取文件的首次提交时间，用作Hexo文章的发布时间"""
    try:
        result = subprocess.run(
            ['git', 'log', '--diff-filter=A', '--format=%cI', '-1', '--', filepath],
            capture_output=True, text=True, check=True
        )
        date_str = result.stdout.strip()
        if date_str:
            return date_str
    except Exception:
        pass
    # fallback to current time
    return datetime.now().strftime('%Y-%m-%dT%H:%M:%S+08:00')

def get_git_update_date(filepath: str) -> str:
    """获取文件的最后一次提交时间，用作Hexo文章的更新时间"""
    try:
        result = subprocess.run(
            ['git', 'log', '--format=%cI', '-1', '--', filepath],
            capture_output=True, text=True, check=True
        )
        date_str = result.stdout.strip()
        if date_str:
            return date_str
    except Exception:
        pass
    return datetime.now().strftime('%Y-%m-%dT%H:%M:%S+08:00')

def clean_java_content(content: str) -> str:
    """清除 LeetCode 插件相关的干扰信息，使用正则只抓取所有的类定义以及类里面的成员"""
    match = re.search(r'(class\s+\w+\s*\{.*)', content, re.DOTALL)
    if match:
        code = match.group(1)
        # 移除末尾可能存在的 LeetCode 结束标记
        code = re.sub(r'//\s*@lc\s+code=end\s*$', '', code).strip()
        return code
    return content.strip()

def extract_oneliner(content: str) -> str:
    """从原始内容中提取一句话题解"""
    code_start = content.find("// @lc code=start")
    code_end   = content.find("// @lc code=end")
    code_section = content[code_start:code_end] if code_start != -1 else content

    javadoc_re = re.compile(r"/\*\*(.*?)\*/", re.DOTALL)
    for m in javadoc_re.finditer(code_section):
        block = m.group(1)
        if "Definition for" in block or "Your " in block:
            continue
        lines = [line.strip().lstrip("*").strip() for line in block.splitlines()]
        lines = [l for l in lines if l]
        if lines:
            return " ".join(lines)
    return "LeetCode 算法题解与代码实现"

def main():
    base_dir = os.path.dirname(os.path.abspath(__file__))
    resolved_dir = os.path.join(base_dir, 'resolved')
    
    # 拆分为 pages（普通页面，不显示在主页）和 posts（博文，显示在主页）
    output_dir = os.path.join(base_dir, '.hexo_dist')
    pages_dir = os.path.join(output_dir, 'pages')
    posts_dir = os.path.join(output_dir, 'posts')
    
    os.makedirs(pages_dir, exist_ok=True)
    os.makedirs(posts_dir, exist_ok=True)
    
    index_links = {}
    
    for root, dirs, files in os.walk(resolved_dir):
        category = os.path.basename(root)
        if category == 'resolved':
            continue
            
        for file in sorted(files):
            if not file.endswith('.java'):
                continue
                
            filepath = os.path.join(root, file)
            title = file[:-5]  # remove .java
            
            with open(filepath, 'r', encoding='utf-8') as f:
                content = f.read()
                
            hint = extract_oneliner(content)
            cleaned_code = clean_java_content(content)
            date_str = get_git_creation_date(filepath)
            updated_str = get_git_update_date(filepath)
            
            # 每道题生成为 page 而非 post，不在主页乱刷屏，而且强制指定 permalink 路径
            md_content = f"""---
title: {title}
date: {date_str}
updated: {updated_str}
layout: page
permalink: /algorithm/{title}/
categories:
  - 算法
  - {category}
tags:
  - LeetCode
---

> {hint}

<!-- more -->

```java
{cleaned_code}
```
"""
            # 写入到 pages_dir
            md_filename = f"{title}.md"
            md_filepath = os.path.join(pages_dir, md_filename)
            with open(md_filepath, 'w', encoding='utf-8') as f:
                f.write(md_content)
                
            if category not in index_links:
                index_links[category] = []
            index_links[category].append(title)
            
    # 生成主页展示的索引文章
    index_content = [
        "---",
        "title: 算法刷题目录",
        f"date: {datetime.now().strftime('%Y-%m-%dT%H:%M:%S+08:00')}",
        "categories:",
        "  - 算法",
        "tags:",
        "  - Index",
        "---",
        ""
    ]
    
    total_count = sum(len(items) for items in index_links.values())
    index_content.append("## 题目统计")
    index_content.append("| 分类 | 数量 | 占比 |")
    index_content.append("| --- | --- | --- |")
    for category in sorted(index_links.keys()):
        count = len(index_links[category])
        percentage = (count / total_count * 100) if total_count > 0 else 0
        index_content.append(f"| **{category}** | {count} | {percentage:.2f}% |")
    index_content.append("")

    for category in sorted(index_links.keys()):
        index_content.append(f"## {category}")
        for title in sorted(index_links[category]):
            # 改为使用标准的相对路径 markdown 链接跳转
            index_content.append(f"* [{title}](/algorithm/{title}/)")
        index_content.append("")
        
    # 索引文章写入到 posts_dir，这样只有这篇会作为 Post 发到博客
    index_filepath = os.path.join(posts_dir, "Algorithm-Index.md")
    with open(index_filepath, 'w', encoding='utf-8') as f:
        f.write('\n'.join(index_content))
        
    print(f"Hexo publisher completed. Output saved to {output_dir}")

if __name__ == "__main__":
    main()
