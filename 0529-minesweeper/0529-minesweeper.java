class Solution {
    private int m, n;
    private int[][] dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    
    public char[][] updateBoard(char[][] board, int[] click) {
        m = board.length;
        n = board[0].length;
        int r = click[0], c = click[1];
        
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        
        dfs(board, r, c);
        return board;
    }
    
    private void dfs(char[][] board, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'E') return;
        
        int mines = countMines(board, r, c);
        if (mines > 0) {
            board[r][c] = (char)('0' + mines);
        } else {
            board[r][c] = 'B';
            for (int[] dir : dirs) {
                dfs(board, r + dir[0], c + dir[1]);
            }
        }
    }
    
    private int countMines(char[][] board, int r, int c) {
        int count = 0;
        for (int[] dir : dirs) {
            int nr = r + dir[0], nc = c + dir[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'M') {
                count++;
            }
        }
        return count;
    }
}