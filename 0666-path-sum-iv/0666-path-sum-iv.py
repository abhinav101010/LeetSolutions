from typing import List

class Solution:
    def pathSum(self, nums: List[int]) -> int:
        if not nums:
            return 0
        # map depth->pos->value
        val = {}
        for num in nums:
            d = num // 100
            p = (num % 100) // 10
            v = num % 10
            val[(d, p)] = v
        def dfs(d, p, cur_sum):
            if (d, p) not in val:
                return 0
            cur_sum += val[(d, p)]
            left = (d+1, p*2-1)
            right = (d+1, p*2)
            if left not in val and right not in val:
                # leaf
                return cur_sum
            return dfs(left[0], left[1], cur_sum) + dfs(right[0], right[1], cur_sum)
        return dfs(1, 1, 0)
