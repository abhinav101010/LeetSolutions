class Solution:
    def wordPatternMatch(self, pattern: str, s: str) -> bool:
        self.res = False
        self.mapping = {}
        self.used = set()
        
        def backtrack(i, j):
            if self.res:
                return
            if i == len(pattern) and j == len(s):
                self.res = True
                return
            if i == len(pattern) or j == len(s):
                return
            p = pattern[i]
            for k in range(j, len(s)):
                sub = s[j:k + 1]
                if p in self.mapping and self.mapping[p] == sub:
                    backtrack(i + 1, k + 1)
                elif p not in self.mapping and sub not in self.used:
                    self.mapping[p] = sub
                    self.used.add(sub)
                    backtrack(i + 1, k + 1)
                    self.used.discard(sub)
                    del self.mapping[p]
        
        backtrack(0, 0)
        return self.res