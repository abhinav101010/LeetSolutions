from typing import List

class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n <= 1:
            return
        
        # Find median using quickselect
        def quickselect(arr, k):
            if len(arr) == 1:
                return arr[0]
            pivot = arr[len(arr) // 2]
            lows = [x for x in arr if x < pivot]
            highs = [x for x in arr if x > pivot]
            pivots = [x for x in arr if x == pivot]
            
            if k < len(lows):
                return quickselect(lows, k)
            elif k < len(lows) + len(pivots):
                return pivot
            else:
                return quickselect(highs, k - len(lows) - len(pivots))
        
        median = quickselect(nums, n // 2)
        
        # 3-way partition (Dutch national flag) with virtual indexing
        def A(i):
            return nums[(1 + 2 * i) % (n | 1)]
        
        def set_A(i, val):
            nums[(1 + 2 * i) % (n | 1)] = val
        
        left, i, right = 0, 0, n - 1
        while i <= right:
            if A(i) > median:
                set_A(left, A(i))
                left += 1
                i += 1
            elif A(i) < median:
                set_A(right, A(i))
                right -= 1
            else:
                i += 1