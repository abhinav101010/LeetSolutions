class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        ans = set()
        for c in word:
            if c.islower():
                if word.find(c.upper()) >= 0:
                    ans.add(c)

        return len(ans)