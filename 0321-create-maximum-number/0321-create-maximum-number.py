from typing import List

class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        def max_subsequence(nums: List[int], k: int) -> List[int]:
            drop = len(nums) - k
            stack = []
            for num in nums:
                while drop and stack and stack[-1] < num:
                    stack.pop()
                    drop -= 1
                stack.append(num)
            return stack[:k]
        
        def merge(a: List[int], b: List[int]) -> List[int]:
            result = []
            while a or b:
                if a > b:
                    result.append(a[0])
                    a = a[1:]
                else:
                    result.append(b[0])
                    b = b[1:]
            return result
        
        best = []
        for i in range(max(0, k - len(nums2)), min(k, len(nums1)) + 1):
            candidate = merge(max_subsequence(nums1, i), max_subsequence(nums2, k - i))
            if candidate > best:
                best = candidate
        return best