class FenwickTree {
public:
    int m, n;
    vector<vector<int>> bit;
    FenwickTree(int m, int n) {
        this->m = m; this->n = n;
        bit.assign(m + 1, vector<int>(n + 1, 0));
    }
    void add(int i, int j, int val) {
        while (i < (int)bit.size()) {
            int jj = j;
            while (jj < (int)bit[0].size()) {
                bit[i][jj] += val;
                jj += (jj & -jj);
            }
            i += (i & -i);
        }
    }
    int query(int i, int j) {
        int res = 0;
        while (i > 0) {
            int jj = j;
            while (jj > 0) {
                res += bit[i][jj];
                jj -= (jj & -jj);
            }
            i -= (i & -i);
        }
        return res;
    }
};

class NumMatrix {
public:
    int m, n;
    vector<vector<int>> matrix;
    FenwickTree* bit;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            m = 0; n = 0; bit = nullptr;
            return;
        }
        m = matrix.size(); n = matrix[0].size();
        this->matrix.assign(m, vector<int>(n, 0));
        bit = new FenwickTree(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != 0) {
                    update(i, j, matrix[i][j]);
                }
            }
        }
    }
    void update(int row, int col, int val) {
        if (matrix[row][col] == val) return;
        int diff = val - matrix[row][col];
        matrix[row][col] = val;
        bit->add(row + 1, col + 1, diff);
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return bit->query(row2 + 1, col2 + 1) - bit->query(row1, col2 + 1) - bit->query(row2 + 1, col1) + bit->query(row1, col1);
    }
};