class Solution {
    public int majorityElement(int[] nums) {
        int cand = 0, count = 0;
        for (int num : nums) {
            if (count == 0) cand = num;
            count += num == cand ? 1 : -1;
        }
        return cand;
    }
}