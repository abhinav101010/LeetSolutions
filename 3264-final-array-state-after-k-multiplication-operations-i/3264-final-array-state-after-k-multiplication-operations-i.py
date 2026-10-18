class Solution:
    def getFinalState(self, nums, k, multiplier):
        pq = [(x, i) for i, x in enumerate(nums)]
        heapify(pq)
        for _ in range(k):
            _, i = heappop(pq)
            nums[i] *= multiplier
            heappush(pq, (nums[i], i))
        return nums
