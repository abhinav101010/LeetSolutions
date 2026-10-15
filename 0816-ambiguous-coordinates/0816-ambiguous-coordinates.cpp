#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        string inner = s.substr(1, s.size() - 2);
        vector<string> res;
        for (size_t i = 1; i < inner.size(); i++) {
            string left = inner.substr(0, i);
            string right = inner.substr(i);
            vector<string> leftOpts = make(left);
            vector<string> rightOpts = make(right);
            for (const string& l : leftOpts) {
                for (const string& r : rightOpts) {
                    res.push_back("(" + l + ", " + r + ")");
                }
            }
        }
        return res;
    }
private:
    vector<string> make(const string& frag) {
        vector<string> res;
        int n = frag.size();
        if (n == 0) return res;
        // no decimal
        if (!(frag[0] == '0' && n > 1)) {
            res.push_back(frag);
        }
        // with decimal
        for (int i = 1; i < n; i++) {
            string left = frag.substr(0, i);
            string right = frag.substr(i);
            if (left.size() > 1 && left[0] == '0') continue;
            if (right.back() == '0') continue;
            res.push_back(left + "." + right);
        }
        return res;
    }
};
