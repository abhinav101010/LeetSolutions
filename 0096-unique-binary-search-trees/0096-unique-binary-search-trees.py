class Solution:
    def numTrees(self, n: int) -> int:
        memo = {}

        def count(low, high):
            if low > high:
                return 1

            if (low, high) in memo:
                return memo[(low, high)]

            ans = 0

            for root in range(low, high + 1):
                left = count(low, root - 1)
                right = count(root + 1, high)
                ans += left * right

            memo[(low, high)] = ans
            return ans

        return count(1, n)