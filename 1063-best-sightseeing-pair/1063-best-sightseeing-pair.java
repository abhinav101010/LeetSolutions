class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int res = 0;
        int bestI = values[0] + 0;
        for (int j = 1; j < values.length; j++) {
            res = Math.max(res, bestI + values[j] - j);
            bestI = Math.max(bestI, values[j] + j);
        }
        return res;
    }
}
