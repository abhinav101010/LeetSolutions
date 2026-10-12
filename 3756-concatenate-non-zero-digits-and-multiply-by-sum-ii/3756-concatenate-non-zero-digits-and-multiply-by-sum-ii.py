class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        # queries.sort()
        # MOD = 10**9 + 7
        # ans = []
        # for i in range(len(queries)):
        #     # tempS = s[queries[i][0]:queries[i][1]+1]
        #     sSum = 0
        #     x = 0
        #     for c in range(queries[i][0],queries[i][1]+1):
        #         if s[c] == "0":
        #             continue
        #         digit = int(s[c])
        #         x = (x * 10 + digit) % MOD
        #         sSum += digit
        #     ans.append((x * sSum) % MOD)
        # return ans

        MOD = 10**9 + 7

        # Keep only non-zero digits and remember their original positions.
        pos = []
        digits = []

        for i, ch in enumerate(s):
            if ch != "0":
                pos.append(i)
                digits.append(int(ch))

        m = len(digits)

        # Prefix sum of digits.
        prefix_sum = [0] * (m + 1)
        for i in range(m):
            prefix_sum[i + 1] = prefix_sum[i] + digits[i]

        # Powers of 10.
        pow10 = [1] * (m + 1)
        for i in range(1, m + 1):
            pow10[i] = (pow10[i - 1] * 10) % MOD

        # Prefix value of the concatenated non-zero digits.
        prefix_val = [0] * (m + 1)
        for i in range(m):
            prefix_val[i + 1] = (prefix_val[i] * 10 + digits[i]) % MOD

        from bisect import bisect_left, bisect_right

        ans = []

        for l, r in queries:
            left = bisect_left(pos, l)
            right = bisect_right(pos, r)

            if left == right:
                ans.append(0)
                continue

            digit_sum = prefix_sum[right] - prefix_sum[left]

            x = (
                prefix_val[right]
                - prefix_val[left] * pow10[right - left]
            ) % MOD

            ans.append((x * digit_sum) % MOD)

        return ans