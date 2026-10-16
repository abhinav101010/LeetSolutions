import java.util.*;
class Solution {
    int[] mp = {0,1,-1,-1,-1,-1,9,-1,8,6};
    int[] digits = {0,1,6,8,9};
    int n;
    int ans = 0;
    public int confusingNumberII(int n) {
        this.n = n;
        dfs(0);
        return ans;
    }
    private void dfs(long num) {
        if (num > n) return;
        long r = 0, t = num;
        while (t > 0) {
            r = r*10 + mp[(int)(t%10)];
            t /= 10;
        }
        if (r != num) ans++;
        for (int d : digits) {
            if (num == 0 && d == 0) continue;
            dfs(num*10 + d);
        }
    }
}
