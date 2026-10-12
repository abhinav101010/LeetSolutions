class Solution {
public:
    double average(vector<int>& salary) {
        int sum = 0;
        int min = INT_MAX;
        int max = INT_MIN;

        for (int s : salary) {
            sum += s;
            if (s < min) {
                min = s;
            }
            if (s > max) {
                max = s;
            }
        }

        return (double)(sum - min - max) / (salary.size() - 2);
    }
};