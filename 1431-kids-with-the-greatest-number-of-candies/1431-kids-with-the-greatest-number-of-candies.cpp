class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = 0;
        for (int candy : candies) {
            if (candy > maxCandy) {
                maxCandy = candy;
            }
        }

        vector<bool> ans;
        for (int candy : candies) {
            ans.push_back(candy + extraCandies >= maxCandy);
        }

        return ans;
    }
};
