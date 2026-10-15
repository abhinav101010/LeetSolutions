import java.util.List;
import java.util.ArrayList;

class Solution {
    public int findBlackPixel(List<List<Character>> picture, int N) {
        if (picture == null || picture.isEmpty() || picture.get(0).isEmpty()) {
            return 0;
        }
        int m = picture.size(), n = picture.get(0).size();
        int[] rows = new int[m];
        int[] cols = new int[n];
        String[] rowStr = new String[m];
        for (int i = 0; i < m; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < n; j++) {
                char c = picture.get(i).get(j);
                sb.append(c);
                if (c == 'B') {
                    rows[i]++;
                    cols[j]++;
                }
            }
            rowStr[i] = sb.toString();
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture.get(i).get(j) == 'B' && rows[i] == N && cols[j] == N) {
                    boolean same = true;
                    for (int r = 0; r < m; r++) {
                        if (picture.get(r).get(j) == 'B' && !rowStr[r].equals(rowStr[i])) {
                            same = false;
                            break;
                        }
                    }
                    if (same) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
}
