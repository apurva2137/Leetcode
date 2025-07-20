from collections import defaultdict
from typing import List

class TrieNode:
    def __init__(self, folder):
        self.folder = folder
        self.children = dict()
        self.remove = False

class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        root = TrieNode("")

        def insert(path):
            node = root
            for folder in path:
                if folder not in node.children:
                    node.children[folder] = TrieNode(folder)
                node = node.children[folder]

        for path in paths:
            insert(path)

        visited = dict()

        def serialize(node):
            if not node.children:
                return ""
            sub = []
            for folder in sorted(node.children):
                sub.append(f"({folder}{serialize(node.children[folder])})")
            serial = "".join(sub)
            if serial in visited:
                visited[serial].remove = True
                node.remove = True
            else:
                visited[serial] = node
            return serial

        for child in root.children.values():
            serialize(child)

        result = []

        def dfs(node, path):
            if node.remove:
                return
            if node.folder:
                path.append(node.folder)
                result.append(path[:])
            for child in node.children.values():
                dfs(child, path)
            if node.folder:
                path.pop()

        for child in root.children.values():
            dfs(child, [])

        return result