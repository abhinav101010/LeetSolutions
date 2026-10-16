#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long S = 0;
        for (int x : nums) if (x % 2 == 0) S += x;
        vector<int> res(queries.size());
        for (size_t k = 0; k < queries.size(); k++) {
            int val = queries[k][0], idx = queries[k][1];
            if (nums[idx] % 2 == 0) S -= nums[idx];
            nums[idx] += val;
            if (nums[idx] % 2 == 0) S += nums[idx];
            res[k] = (int)S;
        }
        return res;
    }
};
