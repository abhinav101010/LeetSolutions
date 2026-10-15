#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool validTicTacToeState(vector<string>& board) {
        int xCount = 0, oCount = 0;
        for (string& row : board) {
            for (char c : row) {
                if (c == 'X') xCount++;
                if (c == 'O') oCount++;
            }
        }
        if (!(xCount == oCount || xCount == oCount + 1)) {
            return false;
        }
        bool xWin = win(board, 'X');
        bool oWin = win(board, 'O');
        if (xWin && oWin) {
            return false;
        }
        if (xWin && xCount != oCount + 1) {
            return false;
        }
        if (oWin && xCount != oCount) {
            return false;
        }
        return true;
    }
private:
    bool win(vector<string>& board, char player) {
        // rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player &&
                board[i][1] == player &&
                board[i][2] == player) {
                return true;
            }
        }
        // cols
        for (int j = 0; j < 3; j++) {
            if (board[0][j] == player &&
                board[1][j] == player &&
                board[2][j] == player) {
                return true;
            }
        }
        // diagonals
        if (board[0][0] == player &&
            board[1][1] == player &&
            board[2][2] == player) {
            return true;
        }
        if (board[0][2] == player &&
            board[1][1] == player &&
            board[2][0] == player) {
            return true;
        }
        return false;
    }
};
