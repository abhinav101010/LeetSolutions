import re

class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        words = re.findall(r'[a-zA-Z]+', paragraph.lower())

        count = {}

        for word in words:
            if word not in banned:
                count[word] = count.get(word, 0) + 1

        return max(count, key=count.get)