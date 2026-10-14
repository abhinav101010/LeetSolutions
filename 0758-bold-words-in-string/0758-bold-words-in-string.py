from typing import List

class Solution:
    def boldWords(self, words: List[str], S: str) -> str:
        n = len(S)
        mark = [False] * n
        for w in words:
            l = len(w)
            start = S.find(w)
            while start != -1:
                for i in range(start, start + l):
                    mark[i] = True
                start = S.find(w, start + 1)
        # build result
        res = []
        i = 0
        while i < n:
            if mark[i]:
                res.append("<b>")
                while i < n and mark[i]:
                    res.append(S[i])
                    i += 1
                res.append("</b>")
            else:
                res.append(S[i])
                i += 1
        return ''.join(res)
