class Solution {
    public boolean canThreePartsEqualSum(int[] arr) {
        int total = 0;
        for (int x : arr) total += x;
        if (total % 3 != 0) return false;
        int target = total / 3;
        int count = 0;
        int cur = 0;
        for (int x : arr) {
            cur += x;
            if (cur == target) {
                count++;
                cur = 0;
            }
        }
        return count >= 3;
    }
}
