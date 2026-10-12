class Solution {
public:
    int getSum(int a, int b) {
        unsigned int mask = 0xFFFFFFFFu;

        unsigned int ua = (unsigned int)a & mask;
        unsigned int ub = (unsigned int)b & mask;

        while (ub != 0) {
            unsigned int carry = (ua & ub) << 1;

            ua = (ua ^ ub) & mask;
            ub = carry & mask;
        }

        if ((ua & 0x80000000u) != 0) {
            return (int)~(ua ^ mask);
        }

        return (int)ua;
    }
};