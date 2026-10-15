class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int ones = 0;
        for (int v : arr) ones += v;
        if (ones % 3 != 0) return {-1,-1};
        if (ones == 0) return {0, n-1};
        int k = ones / 3;
        int first = 0, second = 0, third = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 1) {
                cnt++;
                if (cnt == 1) first = i;
                else if (cnt == k+1) second = i;
                else if (cnt == 2*k+1) {
                    third = i;
                    break;
                }
            }
        }
        while (third < n) {
            if (arr[first] == arr[second] && arr[second] == arr[third]) {
                ++first; ++second; ++third;
            } else return {-1,-1};
        }
        return {first-1, second};
    }
};
