#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        int n = S.size();
        int m = T.size();
        if (m == 0) return "";
        int bestLen = INT_MAX;
        int bestStart = -1;
        int i = 0;
        while (i < n) {
            if (S[i] != T[0]) {
                i++;
                continue;
            }
            // forward match
            int j = i;
            int k = 0;
            while (j < n && k < m) {
                if (S[j] == T[k]) {
                    k++;
                }
                j++;
            }
            if (k != m) {
                i++;
                continue;
            }
            int end = j - 1;
            // backward to tighten start
            int t = m - 1;
            int start = end;
            while (t >= 0) {
                if (S[start] == T[t]) {
                    t--;
                }
                start--;
            }
            start++; // because we went one extra
            int windowLen = end - start + 1;
            if (windowLen < bestLen || (windowLen == bestLen && start < bestStart)) {
                bestLen = windowLen;
                bestStart = start;
            }
            i = start + 1;
        }
        if (bestStart == -1) return "";
        return S.substr(bestStart, bestLen);
    }
};
