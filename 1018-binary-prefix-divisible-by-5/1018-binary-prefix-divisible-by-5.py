class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        ans = []
        curr = ""
        for num in nums:
            curr+=str(num)
            if int(curr, 2)%5 == 0:
                ans.append(True)
            else:
                ans.append(False)
        return ans