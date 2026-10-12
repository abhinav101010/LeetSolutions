class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int maxRadius = 0;
        int i = 0;
        
        for (int house : houses) {
            while (i < (int)heaters.size() - 1 && 
                   abs(heaters[i + 1] - house) <= abs(heaters[i] - house)) {
                i++;
            }
            maxRadius = max(maxRadius, abs(heaters[i] - house));
        }
        
        return maxRadius;
    }
};