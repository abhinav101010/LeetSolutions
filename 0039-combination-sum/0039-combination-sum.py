class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        # ans = []
        # def subsets(nums, i, curr):
        #     nonlocal ans
        #     if i == len(nums):
        #         s = 0
        #         for n in curr:
        #             s+=n
        #         if s == target: ans.append(curr)
        #         return
        #     subsets(nums, i + 1, curr)
        #     subsets(nums, i + 1, curr + [nums[i]])

        # subsets(candidates, 0, [])
        # return ans

        ans = set()
        def nCombo(nums, curr):
            s = sum(curr)

            if s == target:
                ans.add(tuple(sorted(curr)))
                return

            if s > target:
                return

            for n in nums:
                nCombo(nums, curr + [n])

        nCombo(candidates, [])

        return list(ans)
