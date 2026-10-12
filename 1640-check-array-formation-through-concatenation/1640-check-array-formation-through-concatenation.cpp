class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int i = 0;
        int n = arr.size();

        while (i < n) {
            bool found = false;

            for (const auto& piece : pieces) {
                if (piece[0] == arr[i]) {
                    if (!equal(arr.begin() + i, arr.begin() + i + piece.size(), piece.begin())) {
                        return false;
                    }

                    i += piece.size();
                    found = true;
                    break;
                }
            }

            if (!found) {
                return false;
            }
        }

        return true;
    }
};