class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        count = 0

        for word in text.split():
            if not any(ch in brokenLetters for ch in word):
                count += 1

        return count