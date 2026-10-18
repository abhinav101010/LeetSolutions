#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
    int ans;
    void backtrack(vector<int> &path, vector<int> &nums, vector<bool> &used) {
        if (path.size() == nums.size()) {
            ans++;
            return;
        }
        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            if (!path.empty()) {
                int s = path.back() + nums[i];
                int r = (int)sqrt(s);
                if (r*r != s) continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(path, nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ans = 0;
        vector<bool> used(nums.size(), false);
        vector<int> path;
        backtrack(path, nums, used);
        return ans;
    }
};
