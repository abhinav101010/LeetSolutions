import java.util.*;

class Solution {
    public int superPow(int a, int[] b) {
        final int MOD = 1337;
        
        int result = 1;
        for (int digit : b) {
            result = modPow(result, 10) * modPow(a, digit) % MOD;
        }
        return result;
    }
    
    private int modPow(int x, int y) {
        int result = 1;
        x %= 1337;
        while (y > 0) {
            if ((y & 1) == 1) result = (result * x) % 1337;
            x = (x * x) % 1337;
            y >>= 1;
        }
        return result;
    }
}