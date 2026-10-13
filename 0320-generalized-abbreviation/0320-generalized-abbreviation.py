from typing import List

class Solution:
    def generateAbbreviations(self, word: str) -> List[str]:
        res = []
        n = len(word)
        
        def backtrack(pos, count, path):
            if pos == n:
                if count > 0:
                    path += str(count)
                res.append(path)
                return
            backtrack(pos + 1, count + 1, path)
            if count > 0:
                backtrack(pos + 1, 0, path + str(count) + word[pos])
            else:
                backtrack(pos + 1, 0, path + word[pos])
        
        backtrack(0, 0, "")
        return res