class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXor = 0, mask = 0;
        
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            unordered_set<int> found;
            for (int num : nums) {
                found.insert(num & mask);
            }
            
            int candidate = maxXor | (1 << i);
            for (int prefix : found) {
                if (found.count(candidate ^ prefix)) {
                    maxXor = candidate;
                    break;
                }
            }
        }
        
        return maxXor;
    }
};