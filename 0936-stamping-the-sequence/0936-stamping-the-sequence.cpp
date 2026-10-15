#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int sLen = stamp.size();
        int tLen = target.size();
        string tArr = target;
        vector<bool> visited(tLen, false);
        vector<int> res;
        bool changed;
        do {
            changed = false;
            for (int i = 0; i <= tLen - sLen; i++) {
                if (!visited[i] && canStamp(i, stamp, tArr)) {
                    stampAt(i, stamp, tArr);
                    visited[i] = true;
                    res.push_back(i);
                    changed = true;
                }
            }
        } while (changed);
        for (char c : tArr) {
            if (c != '*') {
                return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
private:
    bool canStamp(int start, const string& stamp, string& arr) {
        bool changed = false;
        for (int i = 0; i < stamp.size(); i++) {
            if (arr[start+i] == '*') continue;
            if (arr[start+i] != stamp[i]) return false;
            changed = true;
        }
        return changed;
    }
    void stampAt(int start, const string& stamp, string& arr) {
        for (int i = 0; i < stamp.size(); i++) {
            arr[start+i] = '*';
        }
    }
};
