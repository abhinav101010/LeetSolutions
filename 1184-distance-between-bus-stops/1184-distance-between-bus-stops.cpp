class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int total = 0;
        for (int d : distance) {
            total += d;
        }

        int curr = 0;
        int n = distance.size();

        while (start != destination) {
            curr += distance[start];
            start = (start + 1) % n;
        }

        return min(curr, total - curr);
    }
};