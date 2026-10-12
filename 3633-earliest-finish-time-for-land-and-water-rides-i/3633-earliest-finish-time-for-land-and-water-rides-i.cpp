class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        for (int i = 0; i < (int)landStartTime.size(); i++) {
            int landFinish = landStartTime[i] + landDuration[i];
            for (int j = 0; j < (int)waterStartTime.size(); j++) {
                int finish = max(landFinish, waterStartTime[j]) + waterDuration[j];
                if (finish < ans) ans = finish;
            }
        }
        for (int i = 0; i < (int)waterStartTime.size(); i++) {
            int waterFinish = waterStartTime[i] + waterDuration[i];
            for (int j = 0; j < (int)landStartTime.size(); j++) {
                int finish = max(waterFinish, landStartTime[j]) + landDuration[j];
                if (finish < ans) ans = finish;
            }
        }
        return ans;
    }
};