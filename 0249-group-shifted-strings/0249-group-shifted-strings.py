from collections import defaultdict
from typing import List

class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        groups = defaultdict(list)
        for s in strings:
            if not s:
                groups[''].append(s)
                continue
            key = []
            for c1, c2 in zip(s, s[1:]):
                diff = (ord(c2) - ord(c1)) % 26
                key.append(str(diff))
            groups['-'.join(key)].append(s)
        return list(groups.values())