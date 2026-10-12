class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        ArrayList<Boolean> ans = new ArrayList<>();

        int maxCandy = candies[0];
        for (int candy : candies) {
            if (candy > maxCandy) {
                maxCandy = candy;
            }
        }

        for (int candy : candies) {
            ans.add(candy + extraCandies >= maxCandy);
        }

        return ans;
    }
}