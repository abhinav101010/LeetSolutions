#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = (int)tokens.size() - 1;
        int score = 0;
        int maxScore = 0;
        while (i <= j) {
            if (P >= tokens[i]) {
                P -= tokens[i];
                score++;
                i++;
                maxScore = max(maxScore, score);
            } else if (score > 0) {
                P += tokens[j];
                score--;
                j--;
            } else {
                break;
            }
        }
        return maxScore;
    }
};
