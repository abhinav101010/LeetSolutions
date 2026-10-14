#include <map>
using namespace std;

class MyCalendarThree {
private:
    map<int, int> delta;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        delta[start]++;
        delta[end]--;
        int ongoing = 0;
        int max = 0;
        for (auto& p : delta) {
            ongoing += p.second;
            if (ongoing > max) {
                max = ongoing;
            }
        }
        return max;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
