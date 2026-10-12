class Solution {
    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == word.charAt(0) && backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean backtrack(char[][] board, String word, int r, int c, int k) {
        if (k == word.length()) {
            return true;
        }
        if (r < 0 || c < 0 || r >= board.length || c >= board[0].length || board[r][c] != word.charAt(k)) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = ' ';

        boolean found = backtrack(board, word, r + 1, c, k + 1)
                || backtrack(board, word, r - 1, c, k + 1)
                || backtrack(board, word, r, c + 1, k + 1)
                || backtrack(board, word, r, c - 1, k + 1);

        board[r][c] = temp;
        return found;
    }
}
