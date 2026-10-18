class Solution:
    def findDelayedArrivalTime(self, arrivalTime, delayedTime):
        return (arrivalTime + delayedTime) % 24