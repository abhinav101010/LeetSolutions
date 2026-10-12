class Solution {
public:
    int magicalString(int n) {
        if (n <= 3) return 1;
        
        vector<int> s = {1, 2, 2};
        int i = 2;
        while ((int)s.size() < n) {
            int nextVal = 3 - s.back();
            for (int j = 0; j < s[i]; j++) {
                s.push_back(nextVal);
            }
            i++;
        }
        
        int count = 0;
        for (int k = 0; k < n; k++) {
            if (s[k] == 1) count++;
        }
        return count;
    }
};