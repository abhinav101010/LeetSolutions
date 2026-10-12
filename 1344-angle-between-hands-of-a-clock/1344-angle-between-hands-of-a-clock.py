class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        hour_angle = (0 if hour == 12 else hour * 30) + 0.5 * minutes
        minute_angle = minutes * 6
        diff = abs(hour_angle - minute_angle)
        return min(diff, 360 - diff)