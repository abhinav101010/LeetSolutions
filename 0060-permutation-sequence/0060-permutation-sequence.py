class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        nums = list(range(1,n+1))
        ans = []
        used = [False] * len(nums)

        def backtrack(path):
            if len(ans) == k: return
            if len(path) == len(nums):
                ans.append(path[:])
                return

            for i in range(len(nums)):
                if used[i]:
                    continue

                used[i] = True
                path.append(nums[i])

                backtrack(path)

                path.pop()
                used[i] = False

        backtrack([])
        return "".join(map(str, ans[-1]))
