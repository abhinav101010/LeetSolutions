#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        bool crush;
        do {
            crush = false;
            vector<vector<bool>> toCrush(m, vector<bool>(n, false));
            // horizontal
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n - 2; j++) {
                    int v = abs(board[i][j]);
                    if (v != 0 && abs(board[i][j+1]) == v && abs(board[i][j+2]) == v) {
                        toCrush[i][j] = toCrush[i][j+1] = toCrush[i][j+2] = true;
                        crush = true;
                    }
                }
            }
            // vertical
            for (int i = 0; i < m - 2; i++) {
                for (int j = 0; j < n; j++) {
                    int v = abs(board[i][j]);
                    if (v != 0 && abs(board[i+1][j]) == v && abs(board[i+2][j]) == v) {
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
                        board[i][j] = 0;
                    }
                }
            }
            // drop columns
            for (int j = 0; j < n; j++) {
                int write = m - 1;
                for (int i = m - 1; i >= 0; i--) {
                    if (board[i][j] != 0) {
                        board[write][j] = board[i][j];
                        write--;
                    }
                }
                for (int i = write; i >= 0; i--) {
                    board[i][j] = 0;
                }
            }
        } while (crush);
        return board;
    }
};
