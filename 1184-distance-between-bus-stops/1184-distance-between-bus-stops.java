class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int total = 0;
        for (int d : distance) {
            total += d;
        }

        int curr = 0;
        int n = distance.length;

        while (start != destination) {
            curr += distance[start];
            start = (start + 1) % n;
        }

        return Math.min(curr, total - curr);
    }
}