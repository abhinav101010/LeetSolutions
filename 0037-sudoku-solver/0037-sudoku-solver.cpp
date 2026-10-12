class Solution {
private:
    array<unordered_set<char>, 9> rows;
    array<unordered_set<char>, 9> cols;
    array<unordered_set<char>, 9> boxes;
    vector<pair<int, int>> emptyCells;
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            rows[i].clear();
            cols[i].clear();
            boxes[i].clear();
        }
        emptyCells.clear();
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    emptyCells.emplace_back(i, j);
                } else {
                    char num = board[i][j];
                    rows[i].insert(num);
                    cols[j].insert(num);
                    boxes[(i / 3) * 3 + j / 3].insert(num);
                }
            }
        }
        
        backtrack(board, 0);
    }
    
private:
    bool backtrack(vector<vector<char>>& board, int idx) {
        if (idx == (int)emptyCells.size()) {
            return true;
        }
        
        auto [i, j] = emptyCells[idx];
        int boxIdx = (i / 3) * 3 + j / 3;
        
        for (char num = '1'; num <= '9'; num++) {
            if (!rows[i].count(num) && !cols[j].count(num) && !boxes[boxIdx].count(num)) {
                board[i][j] = num;
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[boxIdx].insert(num);
                
                if (backtrack(board, idx + 1)) {
                    return true;
                }
                
                board[i][j] = '.';
                rows[i].erase(num);
                cols[j].erase(num);
                boxes[boxIdx].erase(num);
            }
        }
        
        return false;
    }
};