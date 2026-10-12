from typing import List

class NumArray:
    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.tree = [0] * (2 * self.n)
        for i in range(self.n):
            self.tree[self.n + i] = nums[i]
        for i in range(self.n - 1, 0, -1):
            self.tree[i] = self.tree[i << 1] + self.tree[i << 1 | 1]
    
    def update(self, index: int, val: int) -> None:
        i = index + self.n
        self.tree[i] = val
        while i > 1:
            i >>= 1
            self.tree[i] = self.tree[i << 1] + self.tree[i << 1 | 1]
    
    def sumRange(self, left: int, right: int) -> int:
        res = 0
        left += self.n
        right += self.n
        while left <= right:
            if left & 1:
                res += self.tree[left]
                left += 1
            if not (right & 1):
                res += self.tree[right]
                right -= 1
            left >>= 1
            right >>= 1
        return res