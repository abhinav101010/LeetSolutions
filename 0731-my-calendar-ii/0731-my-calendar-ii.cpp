#include <vector>
using namespace std;

class MyCalendarTwo {
private:
    vector<pair<int,int>> calendar;
    vector<pair<int,int>> overlap;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // check triple booking
        for (auto& iv : overlap) {
            int s = iv.first;
            int e = iv.second;
            if (!(end <= s || start >= e)) {
                return false;
            }
        }
        vector<pair<int,int>> newOverlaps;
        for (auto& iv : calendar) {
            int s = iv.first;
            int e = iv.second;
            if (!(end <= s || start >= e)) {
                int sOverlap = max(start, s);
                int eOverlap = min(end, e);
                newOverlaps.push_back({sOverlap, eOverlap});
            }
        }
        for (auto& p : newOverlaps) {
            overlap.push_back(p);
        }
        calendar.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
