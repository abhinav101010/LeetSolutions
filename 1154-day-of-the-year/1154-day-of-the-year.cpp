#include <string>
#include <vector>

class Solution {
public:
    int dayOfYear(std::string date) {
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));

        std::vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        bool leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);

        int ans = 0;
        for (int i = 1; i < month; i++) {
            ans += days[i];
        }
        ans += day;

        if (leap && month > 2) {
            ans++;
        }

        return ans;
    }
};