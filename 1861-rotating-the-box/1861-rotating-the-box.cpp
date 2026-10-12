class Solution {
public:
    vector<vector<char>> applyGravity(vector<vector<char>>& boxGrid) {
        bool moved = true;
        while (moved) {
            moved = false;
            for (int i = boxGrid.size() - 2; i >= 0; i--) {
                for (int j = 0; j < boxGrid[i].size(); j++) {

                    if (boxGrid[i][j] == '#') {
                        if (boxGrid[i + 1][j] == '.') {
                            boxGrid[i][j] = '.';
                            boxGrid[i + 1][j] = '#';
                            moved = true;
                        }
                    }
                }
            }
        }

        return boxGrid;
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> result;

        for (int col = 0; col < n; col++) {
            vector<char> row;

            for (int r = m - 1; r >= 0; r--) {
                row.push_back(boxGrid[r][col]);
            }

            result.push_back(row);
        }

        result = applyGravity(result);

        return result;
    }
};