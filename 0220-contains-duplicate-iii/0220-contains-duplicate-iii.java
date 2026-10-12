import java.util.*;

class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
        if (valueDiff < 0) return false;
        
        Map<Long, Long> bucket = new HashMap<>();
        long width = (long) valueDiff + 1;
        
        for (int i = 0; i < nums.length; i++) {
            long num = nums[i];
            long bucketId = num / width;
            if (num < 0) bucketId--;
            
            if (bucket.containsKey(bucketId)) return true;
            
            if (bucket.containsKey(bucketId - 1) && Math.abs(num - bucket.get(bucketId - 1)) < width) {
                return true;
            }
            
            if (bucket.containsKey(bucketId + 1) && Math.abs(num - bucket.get(bucketId + 1)) < width) {
                return true;
            }
            
            bucket.put(bucketId, num);
            
            if (i >= indexDiff) {
                long oldNum = nums[i - indexDiff];
                long oldBucketId = oldNum / width;
                if (oldNum < 0) oldBucketId--;
                bucket.remove(oldBucketId);
            }
        }
        
        return false;
    }
}