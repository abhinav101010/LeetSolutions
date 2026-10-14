# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
# class ArrayReader:
#     def get(self, index: int) -> int:

class Solution:
    def search(self, reader: 'ArrayReader', target: int) -> int:
        # find bounds
        lo, hi = 0, 1
        while reader.get(hi) < target:
            lo = hi
            hi <<= 1
        # binary search
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            val = reader.get(mid)
            if val == target:
                return mid
            elif val > target:
                hi = mid - 1
            else:
                lo = mid + 1
        return -1
