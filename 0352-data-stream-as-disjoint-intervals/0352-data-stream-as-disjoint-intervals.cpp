class SummaryRanges {
private:
    vector<vector<int>> intervals;
    
public:
    SummaryRanges() {}
    
    void addNum(int value) {
        int left = 0, right = intervals.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (intervals[mid][0] < value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (left > 0 && intervals[left - 1][1] + 1 >= value) {
            left--;
        }
        
        int newStart = value, newEnd = value;
        while (left < (int)intervals.size() && intervals[left][0] <= newEnd + 1) {
            newStart = min(newStart, intervals[left][0]);
            newEnd = max(newEnd, intervals[left][1]);
            intervals.erase(intervals.begin() + left);
        }
        
        intervals.insert(intervals.begin() + left, {newStart, newEnd});
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
};