class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        using T = tuple<int, int, int>; // val, row, col
        priority_queue<T, vector<T>, greater<T>> pq;
        
        for (int i = 0; i < min(k, n); i++) {
            pq.emplace(matrix[i][0], i, 0);
        }
        
        int result = 0;
        for (int i = 0; i < k; i++) {
            auto [val, row, col] = pq.top();
            pq.pop();
            result = val;
            if (col + 1 < n) {
                pq.emplace(matrix[row][col + 1], row, col + 1);
            }
        }
        
        return result;
    }
};