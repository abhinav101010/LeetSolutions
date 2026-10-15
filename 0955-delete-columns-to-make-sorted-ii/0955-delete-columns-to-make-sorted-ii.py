class Solution:
    def minDeletionSize(self, strs: list[str]) -> int:
        n = len(strs)
        m = len(strs[0])
        # sorted[i] indicates whether row i is already known to be less than row i+1
        sorted = [False] * (n-1)
        ans = 0
        for col in range(m):
            # check if we can keep this column
            ok = True
            for i in range(n-1):
                if not sorted[i] and strs[i][col] > strs[i+1][col]:
                    ok = False
                    break
            if not ok:
                ans += 1
                continue
            # otherwise, we keep it and update sorted
            for i in range(n-1):
                if not sorted[i] and strs[i][col] < strs[i+1][col]:
                    sorted[i] = True
        return ans
