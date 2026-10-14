#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        deque<int> stack;
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && temperatures[stack.back()] < temperatures[i]) {
                int prev = stack.back();
                stack.pop_back();
                ans[prev] = i - prev;
            }
            stack.push_back(i);
        }
        return ans;
    }
};
