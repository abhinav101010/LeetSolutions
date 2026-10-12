class Solution {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        char slowest = keysPressed.charAt(0);
        int maxTime = releaseTimes[0];

        for (int i = 1; i < releaseTimes.length; i++) {
            int time = releaseTimes[i] - releaseTimes[i - 1];

            if (time > maxTime || (time == maxTime && keysPressed.charAt(i) > slowest)) {
                maxTime = time;
                slowest = keysPressed.charAt(i);
            }
        }

        return slowest;
    }
}