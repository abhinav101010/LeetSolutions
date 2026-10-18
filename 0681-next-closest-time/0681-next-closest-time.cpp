#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
        unordered_set<char> allowed(time.begin(), time.end());
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int start = h * 60 + m;
        for (int offset = 1; offset <= 24 * 60; offset++) {
            int cand = (start + offset) % (24 * 60);
            int hh = cand / 60;
            int mm = cand % 60;
            string cand_str = to_string(hh * 100 + mm);
            // ensure 4-digit zero-padded
            while (cand_str.size() < 4) cand_str = "0" + cand_str;
            string time_str = cand_str.substr(0, 2) + ":" + cand_str.substr(2, 2);
            bool ok = true;
            for (char ch : time_str) {
                if (ch != ':' && allowed.find(ch) == allowed.end()) {
                    ok = false;
                    break;
                }
            }
            if (ok) return time_str;
        }
        return time;
    }
};