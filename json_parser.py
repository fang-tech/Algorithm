import io
import sys
from typing import TextIO, TypeAlias




class JSONDecodeError(ValueError):
    pass


def loads(text: str) -> dict:
    # 整个结构是树状的
    # {
    #     "name": "Alice",
    #     "active": true,
    #     "address": null,
    #     "scores": [98, 87.5, 100],
    #     "profile": {
    #         "languages": ["Python", "Java"],
    #         "settings": {
    #             "notifications": false
    #         }
    #     }
    # }
    # 整个dict是root, bfs/dfs还原这棵树, 以dict的形式建设树
    result = {}
    return result

    def dfs() -> JSONValue:
        raise NotImplementedError

    raise NotImplementedError


def load(file: TextIO) -> dict:
    raise NotImplementedError


def run_text_tests() -> None:
    assert loads("null") is None
    assert loads("true") is True
    assert loads("false") is False

    number_cases = [
        ("0", 0),
        ("-0", 0),
        ("123", 123),
        ("-456", -456),
        ("3.14", 3.14),
        ("-0.25", -0.25),
        ("1e3", 1000.0),
        ("2E-2", 0.02),
        ("-3.5e+2", -350.0),
    ]
    for text, expected in number_cases:
        assert loads(text) == expected, text

    string_cases = [
        ('""', ""),
        ('"hello"', "hello"),
        ('"你好"', "你好"),
        ('"say: \\"hello\\""', 'say: "hello"'),
        ('"a\\\\b"', "a\\b"),
        ('"a\\/b"', "a/b"),
        ('"a\\bb"', "a\bb"),
        ('"a\\fb"', "a\fb"),
        ('"a\\nb"', "a\nb"),
        ('"a\\rb"', "a\rb"),
        ('"a\\tb"', "a\tb"),
        ('"\\u4f60\\u597d"', "你好"),
        ('"\\ud83d\\ude00"', "😀"),
    ]
    for text, expected in string_cases:
        assert loads(text) == expected, text

    assert loads("[]") == []
    assert loads("[1, 2, 3]") == [1, 2, 3]
    assert loads('[null, true, false, "text", -1, 2.5]') == [
        None,
        True,
        False,
        "text",
        -1,
        2.5,
    ]

    assert loads("{}") == {}
    assert loads('{"name": "Alice", "age": 18}') == {
        "name": "Alice",
        "age": 18,
    }
    assert loads('{"value": 1, "value": 2}') == {"value": 2}
    assert loads('{"user": {"name": "Alice"}, "values": [1, 2]}') == {
        "user": {"name": "Alice"},
        "values": [1, 2],
    }
    assert loads(" \t\r\n [ 1,\n2,\t3 ] \r\n") == [1, 2, 3]

    document = """
    {
        "name": "Alice",
        "active": true,
        "address": null,
        "scores": [98, 87.5, 100],
        "profile": {
            "languages": ["Python", "Java"],
            "settings": {
                "notifications": false
            }
        }
    }
    """
    assert loads(document) == {
        "name": "Alice",
        "active": True,
        "address": None,
        "scores": [98, 87.5, 100],
        "profile": {
            "languages": ["Python", "Java"],
            "settings": {"notifications": False},
        },
    }

    invalid_inputs = [
        "",
        "   ",
        '{"name": "Alice"',
        "[1, 2,]",
        '{"name": "Alice",}',
        '{"name" "Alice"}',
        "{name: 1}",
        "{1: 2}",
        '"hello',
        "true false",
        "01",
        "-01",
        "+1",
        ".5",
        "1.",
        "1e",
        "1e+",
        "NaN",
        "Infinity",
        '{"value": undefined}',
        '{"a": 1}}',
        "[1 2]",
        '"\\x41"',
        '"\\u12G4"',
        '"line\nbreak"',
    ]
    for invalid_text in invalid_inputs:
        try:
            loads(invalid_text)
        except JSONDecodeError:
            pass
        else:
            raise AssertionError(
                f"输入 {invalid_text!r} 应当抛出 JSONDecodeError"
            )

    try:
        loads('{"name" "Alice"}')
    except JSONDecodeError as error:
        message = str(error).lower()
        assert any(
            word in message for word in ("position", "line", "column", "char")
        ), f"错误信息需要包含出错位置，实际信息为：{error}"
    else:
        raise AssertionError("不合法的 JSON 应当抛出 JSONDecodeError")

    assert issubclass(JSONDecodeError, ValueError)
    print("text 测试通过")


def run_file_tests() -> None:
    cases = [
        ('{"items": [1, 2, 3]}', {"items": [1, 2, 3]}),
        ("[true, false, null]", [True, False, None]),
        (' \n {"message": "hello\\nworld"} \n ', {"message": "hello\nworld"}),
    ]
    for content, expected in cases:
        file = io.StringIO(content)
        assert load(file) == expected, content

    invalid_file = io.StringIO('{"name": "Alice",}')
    try:
        load(invalid_file)
    except JSONDecodeError:
        pass
    else:
        raise AssertionError("文件中的不合法 JSON 应当抛出 JSONDecodeError")

    print("file 测试通过")


if __name__ == "__main__":
    if len(sys.argv) != 2 or sys.argv[1] not in {"text", "file", "all"}:
        print("用法: python3 json_parser.py [text|file|all]")
        raise SystemExit(2)

    mode = sys.argv[1]
    if mode in {"text", "all"}:
        run_text_tests()
    if mode in {"file", "all"}:
        run_file_tests()

    print("所选测试全部通过")
