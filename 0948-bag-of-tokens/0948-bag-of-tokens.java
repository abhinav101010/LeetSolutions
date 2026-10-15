import java.util.Arrays;
class Solution {
    public int bagOfTokensScore(int[] tokens, int P) {
        Arrays.sort(tokens);
        int i = 0, j = tokens.length - 1;
        int score = 0;
        int maxScore = 0;
        while (i <= j) {
            if (P >= tokens[i]) {
                P -= tokens[i];
                score++;
                i++;
                maxScore = Math.max(maxScore, score);
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
}
