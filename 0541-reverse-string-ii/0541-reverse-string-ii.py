class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        ans = ""
        reverseIT = True

        for i in range(0, len(s), k):
            part = s[i:i+k]

            if reverseIT:
                ans += part[::-1]
            else:
                ans += part

            reverseIT = not reverseIT

        return ans