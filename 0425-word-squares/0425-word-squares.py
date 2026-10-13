from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.words = []

class Trie:
    def __init__(self, words):
        self.root = TrieNode()
        for word in words:
            self.insert(word)
    
    def insert(self, word):
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
            node.words.append(word)
    
    def start_with(self, prefix):
        node = self.root
        for c in prefix:
            if c not in node.children:
                return []
            node = node.children[c]
        return node.words

class Solution:
    def wordSquares(self, words: List[str]) -> List[List[str]]:
        n = len(words[0])
        trie = Trie(words)
        res = []
        
        def backtrack(path):
            if len(path) == n:
                res.append(path[:])
                return
            idx = len(path)
            prefix = ''.join(p[idx] for p in path)
            for w in trie.start_with(prefix):
                path.append(w)
                backtrack(path)
                path.pop()
        
        backtrack([])
        return res