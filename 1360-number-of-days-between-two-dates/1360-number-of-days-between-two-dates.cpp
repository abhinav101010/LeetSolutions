#include <string>
#include <ctime>
using namespace std;

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        auto parse = [](const string& s) -> time_t {
            struct tm tm = {0};
            tm.tm_year = stoi(s.substr(0, 4)) - 1900;
            tm.tm_mon = stoi(s.substr(5, 2)) - 1;
            tm.tm_mday = stoi(s.substr(8, 2));
            return mktime(&tm);
        };
        time_t t1 = parse(date1);
        time_t t2 = parse(date2);
        return abs(int((t1 - t2) / 86400));
    }
};