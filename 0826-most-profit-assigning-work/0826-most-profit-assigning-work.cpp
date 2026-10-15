#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int,int>> jobs;
        for (int i = 0; i < n; ++i)
            jobs.push_back({difficulty[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        vector<int> maxProfitUpTo(10001,0);
        int idx = 0, curMax = 0;
        for (int d = 0; d <= 10000; ++d) {
            while (idx < n && jobs[idx].first == d) {
                curMax = max(curMax, jobs[idx].second);
                ++idx;
            }
            maxProfitUpTo[d] = curMax;
        }
        int total = 0;
        for (int ability : worker) {
            if (ability > 10000) ability = 10000;
            total += maxProfitUpTo[ability];
        }
        return total;
    }
};
