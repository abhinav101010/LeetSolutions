#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MOD = 1000000007;
        vector<tuple<long long, int, long long, long long>> events; // x, type, y1, y2
        set<long long> ySet;
        for (auto& r : rectangles) {
            long long x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            events.push_back({x1, 1, y1, y2});
            events.push_back({x2, -1, y1, y2});
            ySet.insert(y1);
            ySet.insert(y2);
        }
        vector<long long> ys(ySet.begin(), ySet.end());
        sort(ys.begin(), ys.end());
        map<long long, int> yToIdx;
        for (int i = 0; i < ys.size(); i++) {
            yToIdx[ys[i]] = i;
        }
        vector<int> cnt(ys.size() - 1, 0);
        sort(events.begin(), events.end());
        long long ans = 0;
        long long prevX = get<0>(events[0]);
        for (auto& e : events) {
            long long x = get<0>(e);
            long long dx = x - prevX;
            if (dx != 0) {
                long long covered = 0;
                for (int i = 0; i < cnt.size(); i++) {
                    if (cnt[i] > 0) {
                        covered += (ys[i+1] - ys[i]);
                    }
                }
                ans = (ans + dx * covered) % MOD;
            }
            prevX = x;
            int typ = get<1>(e);
            long long y1 = get<2>(e);
            long long y2 = get<3>(e);
            int iIdx = yToIdx[y1];
            int jIdx = yToIdx[y2];
            for (int k = iIdx; k < jIdx; k++) {
                cnt[k] += typ;
            }
        }
        return (int) ans;
    }
};
