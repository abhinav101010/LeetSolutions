class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = set()
        for n in nums:
            if n in ans:
                ans.remove(n)
            else:
                ans.add(n)
        return ans.pop()
