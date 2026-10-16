class Solution {
public:
    int brokenCalc(int x, int y) {
        if (x >= y) return x - y;
        int ans = 0;
        while (y > x) {
            if (y % 2 == 1) y++;
            else y /= 2;
            ans++;
        }
        return ans + x - y;
    }
};
