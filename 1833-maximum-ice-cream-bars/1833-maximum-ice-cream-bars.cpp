class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
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
};