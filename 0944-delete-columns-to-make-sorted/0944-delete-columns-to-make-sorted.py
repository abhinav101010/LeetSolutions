class Solution:
    def minDeletionSize(self, strs: list[str]) -> int:
        if not strs:
            return 0
        m = len(strs[0])
        ans = 0
        for col in range(m):
            for row in range(1, len(strs)):
                if strs[row][col] < strs[row-1][col]:
                    ans += 1
                    break
        return ans
