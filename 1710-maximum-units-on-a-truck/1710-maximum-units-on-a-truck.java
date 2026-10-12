class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        java.util.Arrays.sort(boxTypes, (a, b) -> Integer.compare(b[1], a[1]));

        int total = 0;
        for (int[] bt : boxTypes) {
            int take = Math.min(bt[0], truckSize);
            total += take * bt[1];
            truckSize -= take;
            if (truckSize == 0) break;
        }

        return total;
    }
}