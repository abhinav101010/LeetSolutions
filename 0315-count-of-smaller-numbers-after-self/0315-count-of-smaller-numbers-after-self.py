from typing import List

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0] * n
        enum = list(enumerate(nums))
        
        def merge_sort(arr):
            if len(arr) <= 1:
                return arr
            mid = len(arr) // 2
            left = merge_sort(arr[:mid])
            right = merge_sort(arr[mid:])
            
            i = j = 0
            while i < len(left) or j < len(right):
                if j == len(right) or (i < len(left) and left[i][1] <= right[j][1]):
                    result[left[i][0]] += j
                    arr[i + j] = left[i]
                    i += 1
                else:
                    arr[i + j] = right[j]
                    j += 1
            return arr
        
        merge_sort(enum)
        return result