from typing import List

class Solution:
    def splitArray(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 7:
            return False
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i+1] = prefix[i] + nums[i]
        # j is the middle split point
        for j in range(3, n-3):
            left_sums = set()
            # i from 1 to j-2
            for i in range(1, j-1):
                sum1 = prefix[i] - prefix[0]
                sum2 = prefix[j] - prefix[i+1]
                if sum1 == sum2:
                    left_sums.add(sum1)
            # k from j+2 to n-2
            for k in range(j+2, n-1):
                sum3 = prefix[k] - prefix[j+1]
                sum4 = prefix[n] - prefix[k+1]
                if sum3 == sum4 and sum3 in left_sums:
                    return True
        return False
