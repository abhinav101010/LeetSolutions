#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_map<int, int> count;

        for (int num : arr1) {
            count[num]++;
        }

        std::vector<int> ans;
        ans.reserve(arr1.size());

        for (int num : arr2) {
            int c = count[num];
            for (int j = 0; j < c; j++) {
                ans.push_back(num);
            }
            count.erase(num);
        }

        std::vector<int> remaining;
        remaining.reserve(count.size());
        for (auto& p : count) {
            remaining.push_back(p.first);
        }
        std::sort(remaining.begin(), remaining.end());

        for (int num : remaining) {
            int c = count[num];
            for (int j = 0; j < c; j++) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};