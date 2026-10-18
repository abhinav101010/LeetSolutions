import java.util.*;
class Solution {
    public int bagOfTokensScore(int[] tokens, int P) {
        Arrays.sort(tokens);
        int l = 0, r = tokens.length-1;
        int score = 0;
        int maxScore = 0;
        while (l <= r) {
            if (P >= tokens[l]) {
                P -= tokens[l];
                l++;
                score++;
                maxScore = Math.max(maxScore, score);
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
}
