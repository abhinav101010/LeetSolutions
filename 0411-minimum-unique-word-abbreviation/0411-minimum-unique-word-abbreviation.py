from typing import List

class Solution:
    def minAbbreviation(self, target: str, dictionary: List[str]) -> str:
        self.res = target
        self.n = len(target)
        dict_list = [d for d in dictionary if len(d) == self.n]
        
        def backtrack(pos, count, abbr):
            if pos == self.n:
                if count > 0:
                    abbr += str(count)
                cand = abbr
                for d in dict_list:
                    if self.is_match(cand, d):
                        return
                if len(cand) < len(self.res) or (len(cand) == len(self.res) and cand < self.res):
                    self.res = cand
                return
            # skip
            backtrack(pos + 1, count + 1, abbr)
            # take
            if count > 0:
                backtrack(pos + 1, 0, abbr + str(count) + target[pos])
            else:
                backtrack(pos + 1, 0, abbr + target[pos])
        
        self.backtrack = backtrack
        backtrack(0, 0, "")
        return self.res
    
    def is_match(self, abbr, word):
        i = j = 0
        while i < len(abbr) and j < len(word):
            if abbr[i].isdigit():
                if abbr[i] == '0': return False
                k = i
                while k < len(abbr) and abbr[k].isdigit(): k += 1
                num = int(abbr[i:k])
                j += num
                i = k
            elif abbr[i] == word[j]:
                i += 1; j += 1
            else:
                return False
        return i == len(abbr) and j == len(word)