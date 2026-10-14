#include <vector>
using namespace std;

class MyCalendar {
private:
    vector<pair<int,int>> intervals;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto& iv : intervals) {
            int s = iv.first;
            int e = iv.second;
            if (!(end <= s || start >= e)) {
                return false;
            }
        }
        intervals.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
