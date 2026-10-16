#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            st.push(i);
            ans += st.size();
        }
        return ans;
    }
};
