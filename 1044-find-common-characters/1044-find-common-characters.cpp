#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        for (char c:A[0]) res.push_back(string(1,c));
        for (int i=1;i<A.size();i++) {
            vector<string> newRes;
            for (char c:A[i]) {
                auto it = find(res.begin(), res.end(), string(1,c));
                if (it != res.end()) {
                    newRes.push_back(string(1,c));
                    res.erase(it);
                }
            }
            res = newRes;
            if (res.empty()) break;
        }
        return res;
    }
};
