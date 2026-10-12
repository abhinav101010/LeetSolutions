class Solution {
    public boolean canThreePartsEqualSum(int[] arr) {
        int total = 0;
        for (int num : arr) {
            total += num;
        }
        if (total % 3 != 0) {
            return false;
        }
        int target = total / 3;
        int curr = 0;
        int parts = 0;
        for (int num : arr) {
            curr += num;
            if (curr == target) {
                parts++;
                curr = 0;
                if (parts == 3) {
                    return true;
                }
            }
        }
        return parts >= 3;
    }
}
