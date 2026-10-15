#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> seen;
        for (const string& s : A) {
            string even, odd;
            for (int i = 0; i < s.size(); i++) {
                if (i % 2 == 0) even += s[i];
                else odd += s[i];
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            seen.insert(even + "#" + odd);
        }
        return (int) seen.size();
    }
};
