import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        for (int[] row : matrix) {
            int rowMin = row[0];
            int j = 0;
            for (int k = 1; k < row.length; k++) {
                if (row[k] < rowMin) {
                    rowMin = row[k];
                    j = k;
                }
            }
            boolean isMax = true;
            for (int[] r : matrix) {
                if (r[j] > rowMin) {
                    isMax = false;
                    break;
                }
            }
            if (isMax) ans.add(rowMin);
        }
        return ans;
    }
}