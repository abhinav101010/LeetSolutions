class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int num = num1; num <= num2; num++) {
            string arr = to_string(num);
            for (int i = 1; i < (int)arr.size() - 1; i++) {
                if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) ans++;
                if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1]) ans++;
            }
        }
        return ans;
    }
};