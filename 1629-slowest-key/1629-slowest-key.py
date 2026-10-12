class Solution:
    def slowestKey(self, releaseTimes, keysPressed):
        slowest = keysPressed[0]
        max_time = releaseTimes[0]

        for i in range(1, len(releaseTimes)):
            time = releaseTimes[i] - releaseTimes[i - 1]

            if time > max_time or (time == max_time and keysPressed[i] > slowest):
                max_time = time
                slowest = keysPressed[i]

        return slowest