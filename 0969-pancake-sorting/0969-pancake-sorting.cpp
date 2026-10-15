#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        for (int target = n; target > 1; target--) {
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (arr[i] == target) {
                    idx = i;
                    break;
                }
            }
            if (idx == target - 1) continue;
            if (idx != 0) {
                reverse(arr.begin(), arr.begin() + idx + 1);
                res.push_back(idx+1);
            }
            reverse(arr.begin(), arr.begin() + target);
            res.push_back(target);
        }
        return res;
    }
};
