from typing import List
from collections import defaultdict

class ValidWordAbbr:
    def __init__(self, dictionary: List[str]):
        self.abbr_map = defaultdict(set)
        for word in dictionary:
            abbr = self._abbreviate(word)
            self.abbr_map[abbr].add(word)
    
    def isUnique(self, word: str) -> bool:
        abbr = self._abbreviate(word)
        if abbr not in self.abbr_map:
            return True
        return self.abbr_map[abbr] == {word}
    
    def _abbreviate(self, word: str) -> str:
        n = len(word)
        if n <= 2:
            return word
        return word[0] + str(n - 2) + word[-1]

# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param_1 = obj.isUnique(word)
