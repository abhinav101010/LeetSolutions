class Solution {
public:
    int flipLights(int n, int presses) {
        if (presses == 0) return 1;
        if (presses == 1) return n >= 2 ? 2 : 1;
        if (presses == 2) {
            if (n == 1) return 2;
            if (n == 2) return 3;
            return 4;
        }
        if (n == 1) return 2;
        if (n == 2) return 4;
        return 8;
    }
};