class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        # ans = []
        # for i in range(1,len(nums)+1):
        #     if i not in nums:
        #         ans.append(i)
        # return ans

        # numsSet = set(nums)
        # set1 = set(list(range(1, len(nums)+1)))
        # print(set1-numsSet)

        numsSet = set(nums)
        set1 = set(range(1, len(nums) + 1))

        return list(set1 - numsSet)
