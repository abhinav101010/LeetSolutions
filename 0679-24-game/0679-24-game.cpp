#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool dfs(vector<double>& nums) {
        if (nums.size() == 1) return fabs(nums[0] - 24) < 1e-6;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                vector<double> nextNums;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) nextNums.push_back(nums[k]);
                }
                char ops[4] = {'+', '-', '*', '/'};
                for (char op : ops) {
                    if ((op == '+' || op == '*') && j > i) continue;
                    if (op == '/' && fabs(nums[j]) < 1e-6) continue;
                    double res = 0;
                    if (op == '+') res = nums[i] + nums[j];
                    else if (op == '-') res = nums[i] - nums[j];
                    else if (op == '*') res = nums[i] * nums[j];
                    else if (op == '/') res = nums[i] / nums[j];
                    nextNums.push_back(res);
                    if (dfs(nextNums)) return true;
                    nextNums.pop_back();
                }
            }
        }
        return false;
    }
    
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int c : cards) nums.push_back(c);
        return dfs(nums);
    }
};