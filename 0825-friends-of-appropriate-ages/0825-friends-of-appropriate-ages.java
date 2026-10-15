class Solution {
    public int numFriendRequests(int[] ages) {
        int[] cnt = new int[121];
        for (int age : ages) {
            cnt[age]++;
        }
        int ans = 0;
        for (int a = 1; a <= 120; a++) {
            if (cnt[a] == 0) continue;
            for (int b = 1; b <= 120; b++) {
                if (cnt[b] == 0) continue;
                if (b <= 0.5 * a + 7) continue;
                if (b > a) continue;
                if (b > 100 && a < 100) continue;
                if (a == b) {
                    ans += cnt[a] * (cnt[a] - 1);
                } else {
                    ans += cnt[a] * cnt[b];
                }
            }
        }
        return ans;
    }
}
