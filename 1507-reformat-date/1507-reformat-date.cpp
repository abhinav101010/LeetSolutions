class Solution {
public:
    string reformatDate(string date) {
        string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

        stringstream ss(date);
        string day, month, year;
        ss >> day >> month >> year;

        int monthNum = 0;
        for (int i = 0; i < 12; i++) {
            if (months[i] == month) {
                monthNum = i + 1;
                break;
            }
        }

        int dayNum = 0;
        for (char c : day) {
            if (c >= '0' && c <= '9') {
                dayNum = dayNum * 10 + (c - '0');
            } else {
                break;
            }
        }

        return year + "-" + (monthNum < 10 ? "0" : "") + to_string(monthNum) + "-" + (dayNum < 10 ? "0" : "") + to_string(dayNum);
    }
};