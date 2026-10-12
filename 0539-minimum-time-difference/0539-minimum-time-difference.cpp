class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        minutes.reserve(timePoints.size());
        for (const string& tp : timePoints) {
            int h = stoi(tp.substr(0, 2));
            int m = stoi(tp.substr(3));
            minutes.push_back(h * 60 + m);
        }
        sort(minutes.begin(), minutes.end());
        
        int minDiff = INT_MAX;
        for (int i = 1; i < (int)minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i-1]);
        }
        minDiff = min(minDiff, minutes[0] + 1440 - minutes.back());
        
        return minDiff;
    }
};