class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });

        int total = 0;
        for (const auto& bt : boxTypes) {
            int take = min(bt[0], truckSize);
            total += take * bt[1];
            truckSize -= take;
            if (truckSize == 0) break;
        }

        return total;
    }
};