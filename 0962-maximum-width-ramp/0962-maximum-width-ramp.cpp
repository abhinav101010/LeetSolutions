#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        deque<int> stack;
        for (int i = 0; i < A.size(); i++) {
            if (stack.empty() || A[i] < A[stack.front()]) {
                stack.push_front(i);
            }
        }
        int ans = 0;
        for (int j = A.size() - 1; j >= 0; j--) {
            while (!stack.empty() && A[stack.front()] <= A[j]) {
                ans = max(ans, j - stack.front());
                stack.pop_front();
            }
        }
        return ans;
    }
};
