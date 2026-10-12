class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        
        while (k > 0) {
            long steps = calcSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }
        
        return curr;
    }
    
private:
    long calcSteps(int n, int curr, int next) {
        long steps = 0;
        while (curr <= n) {
            steps += min((long)n + 1, (long)next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};