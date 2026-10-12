class Solution {
    public double angleClock(int hour, int minutes) {
        double hourAngle = (hour == 12 ? 0 : hour * 30.0) + 0.5 * minutes;
        double minuteAngle = minutes * 6.0;
        double diff = Math.abs(hourAngle - minuteAngle);
        return Math.min(diff, 360 - diff);
    }
}