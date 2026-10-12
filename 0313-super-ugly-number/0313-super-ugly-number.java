import java.util.*;

class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] ugly = new int[n];
        ugly[0] = 1;
        int[] idx = new int[primes.length];
        int[] val = primes.clone();
        
        for (int i = 1; i < n; i++) {
            int nextUgly = val[0];
            for (int v : val) nextUgly = Math.min(nextUgly, v);
            ugly[i] = nextUgly;
            
            for (int j = 0; j < primes.length; j++) {
                if (val[j] == nextUgly) {
                    idx[j]++;
                    val[j] = ugly[idx[j]] * primes[j];
                }
            }
        }
        
        return ugly[n - 1];
    }
}