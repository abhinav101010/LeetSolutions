class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        w1 = sum(nums[:k])
        dp1 = [0] * n
        index1 = [0] * n
        dp1[k - 1] = w1
        index1[k - 1] = 0
        for i in range(k, n):
            w1 = w1 - nums[i - k] + nums[i]
            if w1 > dp1[i - 1]:
                dp1[i] = w1
                index1[i] = i - k + 1
            else:
                dp1[i] = dp1[i - 1]
                index1[i] = index1[i - 1]
        
        w2 = sum(nums[k:k + k])
        dp2 = [0] * n
        index2 = [[0, k]] * n
        dp2[2 * k - 1] = dp1[k - 1] + w2
        index2[2 * k - 1] = [index1[k - 1], k]
        for i in range(2 * k, n):
            w2 = w2 - nums[i - k] + nums[i]
            if dp1[i - k] + w2 > dp2[i - 1]:
                dp2[i] = dp1[i - k] + w2
                index2[i] = [index1[i - k], i - k + 1]
            else:
                dp2[i] = dp2[i - 1]
                index2[i] = index2[i - 1]
        
        w3 = sum(nums[2 * k:3 * k])
        dp3 = 0
        res = []
        for i in range(3 * k - 1, n):
            if i == 3 * k - 1:
                dp3 = dp2[2 * k - 1] + w3
                res = index2[2 * k - 1] + [2 * k]
            else:
                w3 = w3 - nums[i - k] + nums[i]
                if dp2[i - k] + w3 > dp3:
                    dp3 = dp2[i - k] + w3
                    res = index2[i - k] + [i - k + 1]
        return res