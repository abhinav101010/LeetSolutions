class Solution:
    def romanToInt(self, s: str) -> int:
        romInt = {
            "M":1000,
            "D":500,
            "C":100,
            "L":50,
            "X":10,
            "V":5,
            "I":1,
        }

        ans = 0
        prev = 0
        for a in s[::-1]:
            if prev > romInt[a]:
                ans -= romInt[a]
            else:
                ans += romInt[a]
            prev = romInt[a]
        return ans

