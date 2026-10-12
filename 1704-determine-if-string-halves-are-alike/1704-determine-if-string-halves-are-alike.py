class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = set("aeiouAEIOU")
        mid = len(s) // 2

        first = 0
        second = 0

        for i in range(mid):
            if s[i] in vowels:
                first += 1

            if s[i + mid] in vowels:
                second += 1

        return first == second