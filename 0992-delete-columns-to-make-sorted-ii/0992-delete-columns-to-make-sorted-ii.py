class Solution:
    def minDeletionSize(self, strs):
        m = len(strs[0])
        n = len(strs)
        sorted_pairs = [False]*(n-1)  # sorted_pairs[i] = True if strs[i] < strs[i+1] already
        ans = 0
        for col in range(m):
            # check if we can keep this column
            delete = False
            for i in range(n-1):
                if not sorted_pairs[i] and strs[i][col] > strs[i+1][col]:
                    delete = True
                    break
            if delete:
                ans += 1
            else:
                # update sorted_pairs where this column makes a strict increase
                for i in range(n-1):
                    if not sorted_pairs[i] and strs[i][col] < strs[i+1][col]:
                        sorted_pairs[i] = True
        return ans
