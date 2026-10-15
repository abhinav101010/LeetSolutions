from typing import List

class Solution:
    def wordsAbbreviation(self, dict: List[str]) -> List[str]:
        n = len(dict)
        # prefix length for each word
        prefix = [1] * n
        def abbr(word, l):
            # l is length of prefix kept
            if len(word) - l <= 2:  # abbreviation not shorter
                return word
            num = len(word) - l - 1
            return word[:l] + str(num) + word[-1]
        # while there is conflict
        changed = True
        while changed:
            changed = False
            # map abbreviation to list of indices
            abbr_map = {}
            for i, word in enumerate(dict):
                a = abbr(word, prefix[i])
                abbr_map.setdefault(a, []).append(i)
            # resolve conflicts
            for a, indices in abbr_map.items():
                if len(indices) > 1:
                    changed = True
                    for i in indices:
                        prefix[i] += 1
        # construct result
        res = []
        for i, word in enumerate(dict):
            res.append(abbr(word, prefix[i]))
        return res
