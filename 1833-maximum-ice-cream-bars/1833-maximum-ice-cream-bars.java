class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int sum = 0;
        int ans = 0;
        for (int cost : costs) {
            if (sum + cost <= coins) {
                sum += cost;
                ans++;
            }
            if (sum == coins) {
                return ans;
            }
        }
        return ans;
    }
}