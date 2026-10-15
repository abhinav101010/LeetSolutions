#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        long long total = 0;
        for (int i = n - 1; i >= 0; i--) {
            total += shifts[i];
            int shift = (int) (total % 26);
            s[i] = (char) ((s[i] - 'a' + shift) % 26 + 'a');
        }
        return s;
    }
};
