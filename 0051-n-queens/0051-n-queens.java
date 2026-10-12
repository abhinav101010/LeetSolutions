import java.util.*;

class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        char[][] board = new char[n][n];
        for (char[] row : board) {
            Arrays.fill(row, '.');
        }
        Set<Integer> cols = new HashSet<>();
        Set<Integer> diag1 = new HashSet<>(); // row + col
        Set<Integer> diag2 = new HashSet<>(); // row - col
        
        backtrack(board, 0, n, cols, diag1, diag2, result);
        return result;
    }
    
    private void backtrack(char[][] board, int row, int n, 
                           Set<Integer> cols, Set<Integer> diag1, Set<Integer> diag2,
                           List<List<String>> result) {
        if (row == n) {
            List<String> solution = new ArrayList<>();
            for (char[] r : board) {
                solution.add(new String(r));
            }
            result.add(solution);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cols.contains(col) || diag1.contains(row + col) || diag2.contains(row - col)) {
                continue;
            }
            
            board[row][col] = 'Q';
            cols.add(col);
            diag1.add(row + col);
            diag2.add(row - col);
            
            backtrack(board, row + 1, n, cols, diag1, diag2, result);
            
            board[row][col] = '.';
            cols.remove(col);
            diag1.remove(row + col);
            diag2.remove(row - col);
        }
    }
}