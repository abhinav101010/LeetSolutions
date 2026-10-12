import java.util.*;

class Solution {
    public int findMaximumXOR(int[] nums) {
        int maxXor = 0, mask = 0;
        
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            Set<Integer> found = new HashSet<>();
            for (int num : nums) {
                found.add(num & mask);
            }
            
            int candidate = maxXor | (1 << i);
            for (int prefix : found) {
                if (found.contains(candidate ^ prefix)) {
                    maxXor = candidate;
                    break;
                }
            }
        }
        
        return maxXor;
    }
}