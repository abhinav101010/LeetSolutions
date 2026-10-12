import java.util.*;

class Solution {
    private Set<Character>[] rows = new HashSet[9];
    private Set<Character>[] cols = new HashSet[9];
    private Set<Character>[] boxes = new HashSet[9];
    private List<int[]> emptyCells = new ArrayList<>();
    
    public void solveSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) {
            rows[i] = new HashSet<>();
            cols[i] = new HashSet<>();
            boxes[i] = new HashSet<>();
        }
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    emptyCells.add(new int[]{i, j});
                } else {
                    char num = board[i][j];
                    rows[i].add(num);
                    cols[j].add(num);
                    boxes[(i / 3) * 3 + j / 3].add(num);
                }
            }
        }
        
        backtrack(board, 0);
    }
    
    private boolean backtrack(char[][] board, int idx) {
        if (idx == emptyCells.size()) {
            return true;
        }
        
        int[] cell = emptyCells.get(idx);
        int i = cell[0], j = cell[1];
        int boxIdx = (i / 3) * 3 + j / 3;
        
        for (char num = '1'; num <= '9'; num++) {
            if (!rows[i].contains(num) && !cols[j].contains(num) && !boxes[boxIdx].contains(num)) {
                board[i][j] = num;
                rows[i].add(num);
                cols[j].add(num);
                boxes[boxIdx].add(num);
                
                if (backtrack(board, idx + 1)) {
                    return true;
                }
                
                board[i][j] = '.';
                rows[i].remove(num);
                cols[j].remove(num);
                boxes[boxIdx].remove(num);
            }
        }
        
        return false;
    }
}