class Solution {
    public int movesToChessboard(int[][] board) {
        int n = board.length;
        // check validity
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) == 1) {
                    return -1;
                }
            }
        }
        int rowCount = 0;
        int colCount = 0;
        for (int i = 0; i < n; i++) {
            rowCount += board[0][i];
            colCount += board[i][0];
        }
        if (rowCount < n/2 || rowCount > (n+1)/2) {
            return -1;
        }
        if (colCount < n/2 || colCount > (n+1)/2) {
            return -1;
        }
        int rowMis = 0;
        int colMis = 0;
        for (int i = 0; i < n; i++) {
            if (board[0][i] == (i % 2)) rowMis++;
            if (board[i][0] == (i % 2)) colMis++;
        }
        int rowSwaps, colSwaps;
        if (n % 2 == 0) {
            rowSwaps = n/2 - Math.max(rowMis, n - rowMis);
            colSwaps = n/2 - Math.max(colMis, n - colMis);
        } else {
            if (rowMis >= n/2) {
                rowSwaps = (n+1)/2 - rowMis;
            } else {
                rowSwaps = rowMis - n/2;
            }
            if (colMis >= n/2) {
                colSwaps = (n+1)/2 - colMis;
            } else {
                colSwaps = colMis - n/2;
            }
        }
        return rowSwaps + colSwaps;
    }
}
