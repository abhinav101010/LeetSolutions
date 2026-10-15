#include <vector>
#include <deque>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        if (n == 0) return -1;
        vector<int> days(n + 1); // 1-indexed
        for (int day = 1; day <= n; day++) {
            int pos = bulbs[day - 1];
            days[pos] = day;
        }
        int window = k + 2;
        if (window > n) return -1;
        int m = n - window + 1; // number of windows
        // arr = days[2..n-1]
        vector<int> arr;
        for (int i = 2; i <= n - 1; i++) {
            arr.push_back(days[i]);
        }
        // sliding window minimum of size k over arr
        deque<int> dq;
        vector<int> minArr(m);
        for (int i = 0; i < (int)arr.size(); i++) {
            while (!dq.empty() && arr[dq.back()] >= arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() <= i - k) {
                dq.pop_front();
            }
            if (i >= k - 1) {
                minArr[i - k + 1] = arr[dq.front()];
            }
        }
        int ans = INT_MAX;
        for (int l = 1; l <= m; l++) {
            int interiorMin = minArr[l - 1];
            int leftDay = days[l];
            int rightDay = days[l + k + 1];
            if (interiorMin > max(leftDay, rightDay)) {
                int cand = max(leftDay, rightDay);
                if (cand < ans) {
                    ans = cand;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
