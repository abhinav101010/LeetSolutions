import collections

class Solution:
    def shortestSubarray(self, nums: list[int], k: int) -> int:
        n = len(nums)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i+1] = prefix[i] + nums[i]
        deque = collections.deque()
        ans = n + 1
        for i in range(n + 1):
            while deque and prefix[i] - prefix[deque[0]] >= k:
                ans = min(ans, i - deque.popleft())
            while deque and prefix[i] <= prefix[deque[-1]]:
                deque.pop()
            deque.append(i)
        return ans if ans <= n else -1
