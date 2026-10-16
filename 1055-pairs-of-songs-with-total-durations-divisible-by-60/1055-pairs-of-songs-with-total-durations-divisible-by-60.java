import java.util.*;
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int[] c = new int[60];
        int ans = 0;
        for (int t : time) {
            int rem = t % 60;
            ans += c[(60 - rem) % 60];
            c[rem]++;
        }
        return ans;
    }
}
