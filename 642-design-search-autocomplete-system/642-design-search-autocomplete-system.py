from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.hot = 0
        self.is_end = False

class AutocompleteSystem:

    def __init__(self, sentences: List[str], times: List[int]):
        self.root = TrieNode()
        self.node = self.root
        self.prefix = ""
        for s, t in zip(sentences, times):
            self.add(s, t)

    def add(self, sentence: str, times: int) -> None:
        node = self.root
        for ch in sentence:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.is_end = True
        node.hot -= times  # store negative for sorting ascending (most hot first)

    def dfs(self, node: TrieNode, path: str, results: List[tuple]) -> None:
        if node.is_end:
            results.append((node.hot, path))
        for ch, child in node.children.items():
            self.dfs(child, path + ch, results)

    def input(self, c: str) -> List[str]:
        if c == '#':
            # end of input
            self.add(self.prefix, 1)
            self.node = self.root
            self.prefix = ""
            return []
        self.prefix += c
        if self.node is None:
            return []
        if c not in self.node.children:
            self.node = None
            return []
        self.node = self.node.children[c]
        res = []
        self.dfs(self.node, self.prefix, res)
        res.sort()  # sort by hot ascending (since hot negative)
        return [sentence for _, sentence in res[:3]]
