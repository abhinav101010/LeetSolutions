#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> res;
        int count = 0;
        int i = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            if (s[j] == '1') {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                string inner = makeLargestSpecial(s.substr(i+1, j - i - 1));
                res.push_back("1" + inner + "0");
                i = j + 1;
            }
        }
        sort(res.rbegin(), res.rend());
        string ans;
        for (string& str : res) {
            ans += str;
        }
        return ans;
    }
};
