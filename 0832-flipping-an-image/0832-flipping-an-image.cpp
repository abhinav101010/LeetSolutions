class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image) {
            int n = row.size();
            for (int i = 0; i < n / 2; i++) {
                swap(row[i], row[n - 1 - i]);
            }
            for (int i = 0; i < n; i++) {
                row[i] ^= 1;
            }
        }
        return image;
    }
};