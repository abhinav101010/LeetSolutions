class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        int res = 0;
        int x = N;
        while (x > 0) {
            res = res * 2 + 1;
            x >>= 1;
        }
        return res ^ N;
    }
};
