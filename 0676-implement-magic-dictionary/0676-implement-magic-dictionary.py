from collections import defaultdict
from typing import List

class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.is_end = False

class MagicDictionary:
    def __init__(self):
        self.root = TrieNode()
        
    def buildDict(self, dictionary: List[str]) -> None:
        for word in dictionary:
            node = self.root
            for c in word:
                node = node.children[c]
            node.is_end = True
        
    def search(self, searchWord: str) -> bool:
        def dfs(node, idx, changed):
            if idx == len(searchWord):
                return node.is_end and changed
            c = searchWord[idx]
            for child_c, child_node in node.children.items():
                if c == child_c:
                    if dfs(child_node, idx + 1, changed):
                        return True
                elif not changed:
                    if dfs(child_node, idx + 1, True):
                        return True
            return False
        return dfs(self.root, 0, False)