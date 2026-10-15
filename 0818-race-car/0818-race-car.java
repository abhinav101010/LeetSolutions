import java.util.*;

class Solution {
    public int racecar(int target) {
        Queue<int[]> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.offer(new int[]{0, 1});
        visited.add("0,1");
        int steps = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] cur = queue.poll();
                int pos = cur[0];
                int speed = cur[1];
                if (pos == target) {
                    return steps;
                }
                // Accelerate
                int newPos = pos + speed;
                int newSpeed = speed * 2;
                String key = newPos + "," + newSpeed;
                if (!visited.contains(key) && Math.abs(newPos) <= 2 * target) {
                    visited.add(key);
                    queue.offer(new int[]{newPos, newSpeed});
                }
                // Reverse
                int newSpeed2 = speed > 0 ? -1 : 1;
                key = pos + "," + newSpeed2;
                if (!visited.contains(key)) {
                    visited.add(key);
                    queue.offer(new int[]{pos, newSpeed2});
                }
            }
            steps++;
        }
        return -1;
    }
}
