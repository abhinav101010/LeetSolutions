#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<tuple<double,int,int>> workers;
        for (int i = 0; i < n; i++) {
            workers.push_back({(double)wage[i]/quality[i], quality[i], wage[i]});
        }
        sort(workers.begin(), workers.end());
        priority_queue<int> maxHeap; // max-heap of quality
        int sumq = 0;
        double ans = 1e18;
        for (auto& t : workers) {
            double ratio = get<0>(t);
            int q = get<1>(t);
            maxHeap.push(q);
            sumq += q;
            if ((int)maxHeap.size() > k) {
                sumq -= maxHeap.top();
                maxHeap.pop();
            }
            if ((int)maxHeap.size() == k) {
                ans = min(ans, ratio * sumq);
            }
        }
        return ans;
    }
};
