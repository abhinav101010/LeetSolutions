import java.util.*;

class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            graph.add(new ArrayList<>());
        }
        int[] indegree = new int[numCourses];
        
        for (int[] pre : prerequisites) {
            int dest = pre[0];
            int src = pre[1];
            graph.get(src).add(dest);
            indegree[dest]++;
        }
        
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) queue.offer(i);
        }
        
        List<Integer> order = new ArrayList<>();
        while (!queue.isEmpty()) {
            int course = queue.poll();
            order.add(course);
            for (int nei : graph.get(course)) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    queue.offer(nei);
                }
            }
        }
        
        if (order.size() != numCourses) return new int[0];
        return order.stream().mapToInt(i -> i).toArray();
    }
}