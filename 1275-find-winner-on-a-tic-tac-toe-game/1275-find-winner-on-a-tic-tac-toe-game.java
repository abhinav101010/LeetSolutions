class Solution {
    public String tictactoe(int[][] moves) {
        String[][] board = new String[3][3];

        for (int i = 0; i < moves.length; i++) {
            int r = moves[i][0];
            int c = moves[i][1];
            board[r][c] = (i % 2 == 0) ? "X" : "O";
        }

        List<String[]> lines = new ArrayList<>();

        // Rows
        for (int r = 0; r < 3; r++) {
            lines.add(board[r]);
        }

        // Columns
        for (int c = 0; c < 3; c++) {
            lines.add(new String[]{board[0][c], board[1][c], board[2][c]});
        }

        // Diagonals
        lines.add(new String[]{board[0][0], board[1][1], board[2][2]});
        lines.add(new String[]{board[0][2], board[1][1], board[2][0]});

        for (String[] line : lines) {
            if (line[0] != null && line[0].equals(line[1]) && line[1].equals(line[2])) {
                return line[0].equals("X") ? "A" : "B";
            }
        }

        if (moves.length == 9) {
            return "Draw";
        }

        return "Pending";
    }
}