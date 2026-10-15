from typing import List

class Solution:
    def addBoldTag(self, s: str, dict: List[str]) -> str:
        n = len(s)
        bold = [False] * n
        for word in dict:
            start = s.find(word)
            while start != -1:
                for i in range(start, start + len(word)):
                    bold[i] = True
                start = s.find(word, start + 1)
        # build result
        res = []
        i = 0
        while i < n:
            if bold[i]:
                res.append('<b>')
                while i < n and bold[i]:
                    res.append(s[i])
                    i += 1
                res.append('</b>')
            else:
                res.append(s[i])
                i += 1
        return ''.join(res)
