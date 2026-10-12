class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        product = 1
        zeroCount = 0

        for num in nums:
            if num != 0:
                product *= num
            else:
                zeroCount += 1

        ans = []

        for num in nums:
            if zeroCount > 1:
                ans.append(0)
            elif zeroCount == 1:
                if num == 0:
                    ans.append(product)
                else:
                    ans.append(0)
            else:
                ans.append(product // num)

        return ans