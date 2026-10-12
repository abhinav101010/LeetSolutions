class Solution {
public:
    int findComplement(int num) {
        int mask = (1 << (32 - __builtin_clz(num))) - 1;
        return num ^ mask;
    }
};