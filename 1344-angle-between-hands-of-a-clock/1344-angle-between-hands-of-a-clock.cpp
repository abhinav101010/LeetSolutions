class Solution {
public:
    double angleClock(int hour, int minutes) {
        return (abs(((hour == 12)? 0 : ((360 / 12) * hour)) + (0.5*minutes)-((360 / 60) * minutes)) > 180)? 360-abs(((hour == 12)? 0 : ((360 / 12) * hour)) + (0.5*minutes)-((360 / 60) * minutes)):abs(((hour == 12)? 0 : ((360 / 12) * hour)) + (0.5*minutes)-((360 / 60) * minutes));
    }
};