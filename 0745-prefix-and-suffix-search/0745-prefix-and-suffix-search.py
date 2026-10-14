from typing import List

class WordFilter:
    def __init__(self, words: List[str]):
        self.mp = {}
        for weight, word in enumerate(words):
            n = len(word)
            for i in range(n+1):
                pre = word[:i]
                for j in range(n+1):
                    suf = word[j:]
                    key = pre + '#' + suf
                    self.mp[key] = weight  # keep max weight

    def f(self, prefix: str, suffix: str) -> int:
        key = prefix + '#' + suffix
        return self.mp.get(key, -1)
