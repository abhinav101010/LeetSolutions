class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];

        int i = 0;
        while (candies > 0) {
            int give = Math.min(candies, i + 1);
            ans[i % num_people] += give;
            candies -= give;
            i++;
        }

        return ans;
    }
}