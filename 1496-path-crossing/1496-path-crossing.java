import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean isPathCrossing(String path) {
        int x = 0;
        int y = 0;
        Set<String> visited = new HashSet<>();
        visited.add(x + "," + y);

        for (char move : path.toCharArray()) {
            if (move == 'N') {
                y += 1;
            } else if (move == 'S') {
                y -= 1;
            } else if (move == 'E') {
                x += 1;
            } else {
                x -= 1;
            }

            String point = x + "," + y;
            if (visited.contains(point)) {
                return true;
            }

            visited.add(point);
        }

        return false;
    }
}