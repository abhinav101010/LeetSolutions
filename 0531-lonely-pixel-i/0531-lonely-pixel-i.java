import java.util.List;
import java.util.ArrayList;

class Solution {
    public int findLonelyPixel(List<List<Character>> picture) {
        if (picture == null || picture.isEmpty() || picture.get(0).isEmpty()) {
            return 0;
        }
        int m = picture.size(), n = picture.get(0).size();
        int[] rows = new int[m];
        int[] cols = new int[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture.get(i).get(j) == 'B') {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int lonely = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture.get(i).get(j) == 'B' && rows[i] == 1 && cols[j] == 1) {
                    lonely++;
                }
            }
        }
        return lonely;
    }
}
