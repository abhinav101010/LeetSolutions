class Solution {
public:
    int bulbSwitch(int n) {
        // The bulbs that are on are those with an odd number of factors
        // Only perfect squares have an odd number of factors
        return (int) sqrt(n);
    }
};