class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int need = m * k;

        for (int i = 0; i + need <= arr.size(); i++) {
            int j = 0;
            while (j < need && arr[i + j] == arr[i + (j % m)]) {
                j++;
            }
            if (j == need) {
                return true;
            }
        }

        return false;
    }
};
