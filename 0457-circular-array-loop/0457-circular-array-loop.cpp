class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            int slow = i, fast = i;
            bool direction = nums[i] > 0;
            
            while (true) {
                slow = nextIndex(nums, slow, direction);
                fast = nextIndex(nums, fast, direction);
                if (fast != -1) fast = nextIndex(nums, fast, direction);
                
                if (slow == -1 || fast == -1) break;
                
                if (slow == fast) {
                    if (slow == nextIndex(nums, slow, direction)) break;
                    return true;
                }
            }
            
            // Mark visited
            slow = i;
            while (nums[slow] * nums[i] > 0) {
                int nxt = nextIndex(nums, slow, direction);
                nums[slow] = 0;
                slow = nxt;
            }
        }
        return false;
    }
    
private:
    int nextIndex(const vector<int>& nums, int i, bool direction) {
        int n = nums.size();
        if ((nums[i] > 0) != direction) return -1;
        int nxt = (i + nums[i]) % n;
        return nxt < 0 ? nxt + n : nxt;
    }
};