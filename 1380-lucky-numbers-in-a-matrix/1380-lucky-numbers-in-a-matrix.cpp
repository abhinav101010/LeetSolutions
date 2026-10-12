#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        for (auto& row : matrix) {
            int rowMin = row[0];
            int j = 0;
            for (int k = 1; k < row.size(); k++) {
                if (row[k] < rowMin) {
                    rowMin = row[k];
                    j = k;
                }
            }
            bool isMax = true;
            for (auto& r : matrix) {
                if (r[j] > rowMin) {
                    isMax = false;
                    break;
                }
            }
            if (isMax) ans.push_back(rowMin);
        }
        return ans;
    }
};