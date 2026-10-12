class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
# Self thought but it gives TLE
        # ans = left
        # for i in range(left + 1, right + 1):
        #     ans &= i
        # return ans

        shift = 0

        while left != right:
            left >>= 1
            right >>= 1
            shift += 1

        return left << shift