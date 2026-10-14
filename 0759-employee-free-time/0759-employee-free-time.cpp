/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;
    Interval() {}
    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
#include <vector>
#include <algorithm>
using namespace std;

class Interval {
public:
    int start;
    int end;
    Interval() {}
    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<pair<int,int>> intervals;
        for (auto& emp : schedule) {
            for (auto& iv : emp) {
                intervals.push_back({iv.start, iv.end});
            }
        }
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>> merged;
        auto cur = intervals[0];
        for (size_t i = 1; i < intervals.size(); i++) {
            auto& nxt = intervals[i];
            if (nxt.first <= cur.second) {
                cur.second = max(cur.second, nxt.second);
            } else {
                merged.push_back(cur);
                cur = nxt;
            }
        }
        merged.push_back(cur);
        vector<Interval> free;
        for (size_t i = 1; i < merged.size(); i++) {
            auto& prev = merged[i-1];
            auto& curr = merged[i];
            if (prev.second < curr.first) {
                free.push_back(Interval(prev.second, curr.first));
            }
        }
        return free;
    }
};
