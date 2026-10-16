#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        for (int i = num.size()-1; i >= 0; i--) {
            int s = num[i] + k;
            k = s / 10;
            res.push_back(s % 10);
        }
        while (k > 0) {
            res.push_back(k % 10);
            k /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
