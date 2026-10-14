import java.util.*;

class Solution {
    public List<List<Integer>> candyCrush(List<List<Integer>> board) {
        int m = board.size();
        int n = board.get(0).size();
        boolean crush;
        do {
            crush = false;
            boolean[][] toCrush = new boolean[m][n];
            // horizontal
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n - 2; j++) {
                    int v = Math.abs(board.get(i).get(j));
                    if (v != 0 && Math.abs(board.get(i).get(j+1)) == v && Math.abs(board.get(i).get(j+2)) == v) {
                        toCrush[i][j] = toCrush[i][j+1] = toCrush[i][j+2] = true;
                        crush = true;
                    }
                }
            }
            // vertical
            for (int i = 0; i < m - 2; i++) {
                for (int j = 0; j < n; j++) {
                    int v = Math.abs(board.get(i).get(j));
                    if (v != 0 && Math.abs(board.get(i+1).get(j)) == v && Math.abs(board.get(i+2).get(j)) == v) {
                        toCrush[i][j] = toCrush[i+1][j] = toCrush[i+2][j] = true;
                        crush = true;
                    }
                }
            }
            if (!crush) break;
            // set to zero
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (toCrush[i][j]) {
                        board.get(i).set(j, 0);
                    }
                }
            }
            // drop columns
            for (int j = 0; j < n; j++) {
                int write = m - 1;
                for (int i = m - 1; i >= 0; i--) {
                    if (board.get(i).get(j) != 0) {
                        board.get(write).set(j, board.get(i).get(j));
                        write--;
                    }
                }
                for (int i = write; i >= 0; i--) {
                    board.get(i).set(j, 0);
                }
            }
        } while (crush);
        return board;
    }
}
