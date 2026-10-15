#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string S = to_string(N);
        int L = S.size();
        int d = D.size();
        int ans = 0;
        // numbers with length < L
        for (int i = 1; i < L; i++) {
            ans += (int) pow(d, i);
        }
        int i = 0;
        while (i < L) {
            char c = S[i];
            int numLess = 0;
            for (string& digit : D) {
                if (digit[0] < c) {
                    numLess++;
                }
            }
            ans += numLess * (int) pow(d, L - i - 1);
            bool found = false;
            for (string& digit : D) {
                if (digit[0] == c) {
                    found = true;
                    break;
                }
            }
            if (!found) break;
            i++;
        }
        if (i == L) {
            ans++; // N itself
        }
        return ans;
    }
};
