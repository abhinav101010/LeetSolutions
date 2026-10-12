class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) {
            return false;
        }

        int gcd = std::gcd(x, y);
        return target % gcd == 0;
    }
};