import json
import os
from os.path import join
from pathlib import Path
from typing import Union

Snippet = dict[str, Union[str, list[str]]]


def snippetize(filename: str) -> Snippet:
    snippet: Snippet = {}
    snippet["prefix"] = Path(filename).stem
    lines: list[str] = Path(filename).read_text().splitlines()
    body: list[str] = []
    is_body: bool = False
    for line in lines:
        if line.startswith("// snippet-end"):
            is_body = False
        elif line.startswith("// snippet-begin"):
            is_body = True
        elif is_body:
            body.append(line)
    snippet["body"] = body
    return snippet


if __name__ == "__main__":
    snippets: dict[str, Snippet] = {}
    for root, _, files in os.walk("./../nimrod"):
        for filename in files:
            if Path(filename).suffix == "cc":
                snippet: Snippet = snippetize(join(root, filename))
                if snippet["body"]:
                    snippets[Path(filename).stem] = snippet
    Path("./output.json").write_text(json.dumps(snippets, indent=4))
