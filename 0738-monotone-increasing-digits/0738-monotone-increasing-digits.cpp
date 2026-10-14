#include <string>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int n = s.size();
        int i = 1;
        while (i < n && s[i-1] <= s[i]) {
            i++;
        }
        if (i < n) {
            while (i > 0 && s[i-1] > s[i]) {
                i--;
            }
            s[i]--;
            for (int j = i+1; j < n; j++) {
                s[j] = '9';
            }
        }
        return stoi(s);
    }
};
