#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int ans = 0;
        int first = -2; // largest selected
        int second = -2; // second largest selected
        for (auto& interval : intervals) {
            int a = interval[0];
            int b = interval[1];
            if (second >= a) {
                continue;
            }
            if (first >= a) {
                ans++;
                second = b;
            } else {
                ans += 2;
                first = b - 1;
                second = b;
            }
        }
        return ans;
    }
};
