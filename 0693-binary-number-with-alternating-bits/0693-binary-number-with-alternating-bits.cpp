class Solution {
public:
    bool hasAlternatingBits(int n) {
        string b = bitset<32>(n).to_string();
        // trim leading zeros? better just check bit sequence; but easier to get from integer by shifting
        int prev = -1;
        while (n > 0) {
            int bit = n & 1;
            if (prev != -1 && prev == bit) {
                return false;
            }
            prev = bit;
            n >>= 1;
        }
        return true;
    }
};
