class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = set()
        seen = set()
        for n in nums:
            if n in ans:
                ans.remove(n)
            elif n not in seen:
                seen.add(n)
                ans.add(n)
        return ans.pop()
