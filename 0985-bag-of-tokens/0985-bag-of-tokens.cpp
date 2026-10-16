#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int l = 0, r = (int)tokens.size()-1;
        int score = 0;
        int maxScore = 0;
        while (l <= r) {
            if (P >= tokens[l]) {
                P -= tokens[l];
                l++;
                score++;
                maxScore = max(maxScore, score);
            } else if (score > 0) {
                P += tokens[r];
                r--;
                score--;
            } else {
                break;
            }
        }
        return maxScore;
    }
};
