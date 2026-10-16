#include <string>
#include <unordered_set>
using namespace std;
class Solution {
    bool hasRepeating(const string &s, int length) {
        unordered_set<string> seen;
        for (int i = 0; i <= (int)s.size()-length; i++) {
            string sub = s.substr(i, length);
            if (seen.count(sub)) return true;
            seen.insert(sub);
        }
        return false;
    }
public:
    int longestRepeatingSubstring(string s) {
        int left = 1, right = s.size();
        int res = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (hasRepeating(s, mid)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};
