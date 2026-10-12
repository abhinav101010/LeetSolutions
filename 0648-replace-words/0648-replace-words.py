from collections import defaultdict
from typing import List

class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        trie = {}
        for word in dictionary:
            node = trie
            for ch in word:
                node = node.setdefault(ch, {})
            node['#'] = True
        
        def find_root(word):
            node = trie
            for i, ch in enumerate(word):
                if ch not in node:
                    return word
                node = node[ch]
                if '#' in node:
                    return word[:i+1]
            return word
        
        return ' '.join(find_root(w) for w in sentence.split())