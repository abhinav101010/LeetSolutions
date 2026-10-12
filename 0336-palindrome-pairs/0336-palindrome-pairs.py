from collections import defaultdict
from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.word_id = -1
        self.palindrome_suffixes = []

class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        root = TrieNode()
        
        for i, word in enumerate(words):
            node = root
            for j, c in enumerate(reversed(word)):
                if c not in node.children:
                    node.children[c] = TrieNode()
                if word[:len(word)-j] == word[:len(word)-j][::-1]:
                    node.palindrome_suffixes.append(i)
                node = node.children[c]
            node.word_id = i
        
        result = []
        for i, word in enumerate(words):
            node = root
            for j, c in enumerate(word):
                if node.word_id != -1 and node.word_id != i:
                    if word[j:] == word[j:][::-1]:
                        result.append([i, node.word_id])
                if c not in node.children:
                    break
                node = node.children[c]
            else:
                if node.word_id != -1 and node.word_id != i:
                    result.append([i, node.word_id])
                for pid in node.palindrome_suffixes:
                    if pid != i:
                        result.append([i, pid])
        
        return result