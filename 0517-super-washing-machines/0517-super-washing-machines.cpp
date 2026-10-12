class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int total = 0;
        for (int m : machines) total += m;
        int n = machines.size();
        if (total % n != 0) return -1;
        int avg = total / n;
        
        int maxMoves = 0;
        int balance = 0;
        for (int m : machines) {
            balance += m - avg;
            maxMoves = max(maxMoves, max(abs(balance), m - avg));
        }
        
        return maxMoves;
    }
};