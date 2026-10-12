class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxOnes = 0, maxZeros = 0;
        int ones = 0, zeros = 0;
        for (char ch : s) {
            if (ch == '1') {
                ones++;
                zeros = 0;
                maxOnes = max(maxOnes, ones);
            } else {
                zeros++;
                ones = 0;
                maxZeros = max(maxZeros, zeros);
            }
        }
        return maxOnes > maxZeros;
    }
};