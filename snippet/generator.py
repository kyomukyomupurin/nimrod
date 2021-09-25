import json
import os
from os.path import join
from pathlib import Path
from typing import Union

Snippet = dict[str, Union[str, list[str], float]]


def snippetize(file: str) -> Snippet:
    snippet: Snippet = {}
    snippet["prefix"] = Path(file).stem
    lines: list[str] = Path(file).read_text().splitlines()
    body: list[str] = []
    is_body: bool = False
    for line in lines:
        if line.startswith("// snippet-end"):
            is_body = False
        elif line.startswith("// snippet-begin"):
            is_body = True
        elif is_body:
            body.append(line)
    if body:
        snippet["body"] = body
    snippet["timestamp"] = Path(file).stat().st_mtime
    return snippet


if __name__ == "__main__":
    exists: bool = Path("./snippet.json").exists()
    snippets: dict[str, Snippet]
    if exists:
        snippets = json.load(Path("./snippet.json").open())
    else:
        snippets = {}
    for root, _, files in os.walk("./../nimrod/"):
        for file in files:
            if (Path(file).suffix) == ".cc":
                """
                1. 初めて snippet.json を作成する場合
                   - スニペット用タグのついたファイルがあったら、スニペットを作成
                2. 既に snippet.json が存在する場合
                   - 差分を更新する
                   2.1 スニペットを作成済みのファイルの場合
                       2.1.1 タイムスタンプが変化している場合（更新あり）
                             - スニペット用タグがついていたら、スニペットを更新
                             - スニペット用タグがついていなかったら、スニペットを削除
                       2.1.2 タイムスタンプが変化していない場合（更新なし）
                             - 何もしない
                   2.2 スニペットを作成していないファイルの場合
                       - スニペット用タグがついていたら、スニペットを作成
                """
                if not exists:
                    snippet: Snippet = snippetize(join(root, file))
                    if "body" in snippet:
                        snippets[Path(file).stem] = snippet
                        print(f"Generated: {Path(file).stem}")
                else:
                    if Path(file).stem in snippets:
                        if snippets[Path(file).stem]["timestamp"] != Path(join(root, file)).stat().st_mtime:
                            snippet: Snippet = snippetize(join(root, file))
                            if "body" in snippet:
                                snippets[Path(file).stem] = snippet
                                print(f"Updated: {Path(file).stem}")
                            else:
                                del snippets[Path(file).stem]
                                print(f"Deleted: {Path(file).stem}")
                        else:
                            print(f"Skipped: {Path(file).stem}")
                    else:
                        snippet: Snippet = snippetize(join(root, file))
                        if "body" in snippet:
                            snippets[Path(file).stem] = snippet
                            print(f"Generated: {Path(file).stem}")
    Path("./snippet.json").write_text(json.dumps(snippets, indent=4))