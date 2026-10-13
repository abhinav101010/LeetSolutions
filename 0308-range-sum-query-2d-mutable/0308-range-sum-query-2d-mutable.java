import java.util.*;

class FenwickTree {
    int m, n;
    int[][] bit;
    public FenwickTree(int m, int n) {
        this.m = m;
        this.n = n;
        bit = new int[m + 1][n + 1];
    }
    public void add(int i, int j, int val) {
        while (i < bit.length) {
            int jj = j;
            while (jj < bit[0].length) {
                bit[i][jj] += val;
                jj += (jj & -jj);
            }
            i += (i & -i);
        }
    }
    public int query(int i, int j) {
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
}

class NumMatrix {
    int m, n;
    int[][] matrix;
    FenwickTree bit;
    public NumMatrix(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            m = 0; n = 0; bit = null; this.matrix = null;
            return;
        }
        m = matrix.length; n = matrix[0].length;
        this.matrix = new int[m][n];
        bit = new FenwickTree(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != 0) {
                    update(i, j, matrix[i][j]);
                }
            }
        }
    }
    public void update(int row, int col, int val) {
        if (matrix[row][col] == val) return;
        int diff = val - matrix[row][col];
        matrix[row][col] = val;
        bit.add(row + 1, col + 1, diff);
    }
    public int sumRegion(int row1, int col1, int row2, int col2) {
        return bit.query(row2 + 1, col2 + 1) - bit.query(row1, col2 + 1) - bit.query(row2 + 1, col1) + bit.query(row1, col1);
    }
}