class Solution {
    int mp[10] = {0,1,-1,-1,-1,-1,9,-1,8,6};
    int digs[5] = {0,1,6,8,9};
    int N, ans = 0;
    void dfs(long num) {
        if (num > N) return;
        long r = 0, t = num;
        while (t) { r = r*10 + mp[t%10]; t /= 10; }
        if (r != num) ans++;
        for (int d : digs) if (!(num==0 && d==0)) dfs(num*10 + d);
    }
public:
    int confusingNumberII(int n) {
        N = n; ans = 0; dfs(0); return ans;
    }
};
