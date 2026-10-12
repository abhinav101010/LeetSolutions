class Solution {
    public boolean isCovered(int[][] ranges, int left, int right) {
        for (int num = left; num <= right; num++) {
            boolean found = false;
            for (int[] range : ranges) {
                if (range[0] <= num && num <= range[1]) {
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
}