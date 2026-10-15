class Solution:
    def findAndReplacePattern(self, words: list[str], pattern: str) -> list[str]:
        def normalize(s):
            mapping = {}
            res = []
            for ch in s:
                if ch not in mapping:
                    mapping[ch] = len(mapping)
                res.append(mapping[ch])
            return res
        pat = normalize(pattern)
        res = []
        for w in words:
            if normalize(w) == pat:
                res.append(w)
        return res
