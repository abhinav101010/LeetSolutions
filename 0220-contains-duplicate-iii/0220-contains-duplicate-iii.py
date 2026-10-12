from typing import List

class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        if valueDiff < 0:
            return False
        
        bucket = {}
        width = valueDiff + 1
        
        for i, num in enumerate(nums):
            bucket_id = num // width
            if num < 0:
                bucket_id -= 1
            
            if bucket_id in bucket:
                return True
            
            if bucket_id - 1 in bucket and abs(num - bucket[bucket_id - 1]) < width:
                return True
            
            if bucket_id + 1 in bucket and abs(num - bucket[bucket_id + 1]) < width:
                return True
            
            bucket[bucket_id] = num
            
            if i >= indexDiff:
                old_num = nums[i - indexDiff]
                old_bucket_id = old_num // width
                if old_num < 0:
                    old_bucket_id -= 1
                del bucket[old_bucket_id]
        
        return False