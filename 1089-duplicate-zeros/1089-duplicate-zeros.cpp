#include <vector>

class Solution {
public:
    void duplicateZeros(std::vector<int>& arr) {
        std::vector<int> ans;
        ans.reserve(arr.size());

        for (int num : arr) {
            if (num == 0) {
                ans.push_back(0);
                ans.push_back(0);
            } else {
                ans.push_back(num);
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = ans[i];
        }
    }
};