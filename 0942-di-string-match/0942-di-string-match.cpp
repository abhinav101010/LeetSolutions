#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int lo = 0, hi = s.size();
        vector<int> res;
        for (char ch : s) {
            if (ch == 'I') {
                res.push_back(lo++);
            } else {
                res.push_back(hi--);
            }
        }
        res.push_back(lo); // lo == hi
        return res;
    }
};
