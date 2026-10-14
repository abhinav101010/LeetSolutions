#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size() + 1;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = i + 1;
        }
        int i = 0;
        while (i < s.size()) {
            if (s[i] == 'I') {
                i++;
                continue;
            }
            int j = i;
            while (j < s.size() && s[j] == 'D') {
                j++;
            }
            // reverse res[i..j]
            int l = i, r = j;
            while (l < r) {
                swap(res[l], res[r]);
                l++;
                r--;
            }
            i = j;
        }
        return res;
    }
};
