class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        if (n < 4) return false;
        
        for (int i = 3; i < n; i++) {
            // Case 1: Fourth line crosses first
            if (x[i] >= x[i-2] && x[i-1] <= x[i-3]) return true;
            // Case 2: Fifth line meets first
            if (i >= 4 && x[i-1] == x[i-3] && x[i] + x[i-4] >= x[i-2]) return true;
            // Case 3: Sixth line crosses first
            if (i >= 5 && x[i-2] >= x[i-4] && x[i] + x[i-4] >= x[i-2] && x[i-1] <= x[i-3] && x[i-1] + x[i-5] >= x[i-3]) return true;
        }
        
        return false;
    }
};