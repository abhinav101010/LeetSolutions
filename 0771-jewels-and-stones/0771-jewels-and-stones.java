class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        int ans = 0;
        for (char stone : stones.toCharArray()) {
            if (jewels.indexOf(stone) >= 0) {
                ans++;
            }
        }
        return ans;
    }
}