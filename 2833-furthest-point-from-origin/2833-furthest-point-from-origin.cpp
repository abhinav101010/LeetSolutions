class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r = 0, l = 0, free = 0;
        for (char c : moves) {
            if (c == 'R') r++;
            else if (c == 'L') l++;
            else free++;
        }
        if (r == l) return free;
        if (r > l) return r - l + free;
        return l - r + free;
    }
};