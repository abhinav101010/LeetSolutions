class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;

        vector<int> secretCount(10, 0);
        vector<int> guessCount(10, 0);

        for (int i = 0; i < secret.size(); i++) {
            char s = secret[i];
            char g = guess[i];
            if (s == g) {
                bulls++;
            } else {
                secretCount[s - '0']++;
                guessCount[g - '0']++;
            }
        }

        for (int i = 0; i < 10; i++) {
            cows += min(secretCount[i], guessCount[i]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};