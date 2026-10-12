class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        nums = list(range(1, n + 1))

        def subsets(i, curr):
            if i == len(nums):
                if len(curr) == k:
                    ans.append(curr)
                return

            subsets(i + 1, curr)
            subsets(i + 1, curr + [nums[i]])

        subsets(0, [])
        return ans