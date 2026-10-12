class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<string>> board(3, vector<string>(3, ""));

        for (int i = 0; i < moves.size(); i++) {
            int r = moves[i][0];
            int c = moves[i][1];
            board[r][c] = (i % 2 == 0) ? "X" : "O";
        }

        vector<vector<string>> lines;

        // Rows
        for (int r = 0; r < 3; r++) {
            lines.push_back(board[r]);
        }

        // Columns
        for (int c = 0; c < 3; c++) {
            lines.push_back({board[0][c], board[1][c], board[2][c]});
        }

        // Diagonals
        lines.push_back({board[0][0], board[1][1], board[2][2]});
        lines.push_back({board[0][2], board[1][1], board[2][0]});

        for (auto& line : lines) {
            if (!line[0].empty() && line[0] == line[1] && line[1] == line[2]) {
                return line[0] == "X" ? "A" : "B";
            }
        }

        if (moves.size() == 9) {
            return "Draw";
        }

        return "Pending";
    }
};