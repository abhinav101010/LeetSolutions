class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minDistance = INT_MAX;
        int answer = -1;

        for (int i = 0; i < (int)points.size(); i++) {
            int px = points[i][0];
            int py = points[i][1];

            if (px == x || py == y) {
                int distance = abs(x - px) + abs(y - py);

                if (distance < minDistance) {
                    minDistance = distance;
                    answer = i;
                }
            }
        }

        return answer;
    }
};