#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        vector<pair<int, int>> rows;
        rows.reserve(m);
        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int val : mat[i]) {
                count += val;
            }
            rows.emplace_back(count, i);
        }
        sort(rows.begin(), rows.end());
        vector<int> result;
        result.reserve(k);
        for (int i = 0; i < k; i++) {
            result.push_back(rows[i].second);
        }
        return result;
    }
};