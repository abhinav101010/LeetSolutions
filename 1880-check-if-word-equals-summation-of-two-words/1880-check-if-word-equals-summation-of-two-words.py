class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        def get_value(word):
            num = 0

            for ch in word:
                num = num * 10 + (ord(ch) - ord('a'))

            return num

        return get_value(firstWord) + get_value(secondWord) == get_value(targetWord)