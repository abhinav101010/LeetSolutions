class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char slowest = keysPressed[0];
        int maxTime = releaseTimes[0];

        for (int i = 1; i < (int)releaseTimes.size(); i++) {
            int time = releaseTimes[i] - releaseTimes[i - 1];

            if (time > maxTime || (time == maxTime && keysPressed[i] > slowest)) {
                maxTime = time;
                slowest = keysPressed[i];
            }
        }

        return slowest;
    }
};