class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        # ans = set()
        # def subsets(nums, i, curr):
        #     nonlocal ans
        #     if i == len(nums):
        #         s = sum(curr)
        #         if s == target: ans.add(tuple(sorted(curr)))
        #         return
        #     subsets(nums, i + 1, curr)
        #     subsets(nums, i + 1, curr + [nums[i]])

        # subsets(candidates, 0, [])
        # return list(ans)

        candidates.sort()
        ans = []
        def subsets(curr, pos ,target):
            if target == 0:
                ans.append(curr.copy())
            if target<=0:
                return

            prev = -1
            for i in range(pos, len(candidates)):
                if candidates[i] == prev:
                    continue
                curr.append(candidates[i])
                subsets(curr, i+1, target - candidates[i])
                curr.pop()
                prev = candidates[i]

        subsets([], 0, target)
        return ans