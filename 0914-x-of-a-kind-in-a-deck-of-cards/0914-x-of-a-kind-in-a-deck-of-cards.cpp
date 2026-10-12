class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        for (int card : deck) {
            count[card]++;
        }
        int x = 0;
        for (auto& p : count) {
            x = gcd(x, p.second);
        }
        return x >= 2;
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};