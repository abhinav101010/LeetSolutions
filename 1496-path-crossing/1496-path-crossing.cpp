class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0;
        int y = 0;
        unordered_set<string> visited;
        visited.insert(to_string(x) + "," + to_string(y));

        for (char move : path) {
            if (move == 'N') {
                y += 1;
            } else if (move == 'S') {
                y -= 1;
            } else if (move == 'E') {
                x += 1;
            } else {
                x -= 1;
            }

            string point = to_string(x) + "," + to_string(y);
            if (visited.count(point)) {
                return true;
            }

            visited.insert(point);
        }

        return false;
    }
};