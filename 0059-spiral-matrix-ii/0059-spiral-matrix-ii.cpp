class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int left = 0, right = n, top = 0, bottom = n, num = 1;
        while (left < right && top < bottom) {
            for (int i = left; i < right; i++) {
                matrix[top][i] = num++;
            }
            top++;

            for (int i = top; i < bottom; i++) {
                matrix[i][right - 1] = num++;
            }
            right--;

            if (left >= right || top >= bottom) {
                break;
            }

            for (int i = right - 1; i >= left; i--) {
                matrix[bottom - 1][i] = num++;
            }
            bottom--;

            for (int i = bottom - 1; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
        return matrix;
    }
};
