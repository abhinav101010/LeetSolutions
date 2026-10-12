from collections import Counter
from typing import List

class Solution:
    def frequencySort(self, s: str) -> str:
        count = Counter(s)
        result = []
        for char, freq in count.most_common():
            result.append(char * freq)
        return "".join(result)