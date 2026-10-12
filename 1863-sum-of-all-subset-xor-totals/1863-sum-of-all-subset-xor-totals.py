class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        def backtrack(i, current_xor):
            if i == len(nums):
                return current_xor

            include = backtrack(i + 1, current_xor ^ nums[i])
            exclude = backtrack(i + 1, current_xor)

            return include + exclude

        return backtrack(0, 0)