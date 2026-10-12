#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101, 0);
        for (int num : nums) freq[num]++;
        vector<int> countLess(101, 0);
        int running = 0;
        for (int i = 0; i <= 100; i++) {
            countLess[i] = running;
            running += freq[i];
        }
        vector<int> ans;
        ans.reserve(nums.size());
        for (int num : nums) ans.push_back(countLess[num]);
        return ans;
    }
};