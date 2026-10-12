class Solution:
    def numDecodings(self, s: str) -> int:

        # ans = 0
        # def permute(curr, i):
        #     nonlocal ans
        #     if (curr and curr[-1][-1] == s[-1] and "".join(curr) == s) or i >= len(s):
        #         ans+=1
        #         return

        #     oneChar = s[i:i+1]
        #     twoChar = s[i:i+2]
        #     if oneChar[0] != "0":
        #         permute(curr+[oneChar], i+1)
        #     if i + 1 < len(s) and twoChar[0] != "0" and int(twoChar) <= 26:
        #         permute(curr + [twoChar], i + 2)

        # permute([], 0)
        # return ans

# My above written code gives TLE, so used memory

        memo = {}

        def permute(i):
            if i == len(s):
                return 1

            if s[i] == "0":
                return 0

            if i in memo:
                return memo[i]

            ans = permute(i + 1)

            if i + 1 < len(s) and int(s[i:i+2]) <= 26:
                ans += permute(i + 2)

            memo[i] = ans
            return ans

        return permute(0)