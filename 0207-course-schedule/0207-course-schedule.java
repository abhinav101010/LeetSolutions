import java.util.*;

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
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
        
        int count = 0;
        while (!queue.isEmpty()) {
            int course = queue.poll();
            count++;
            for (int nei : graph.get(course)) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    queue.offer(nei);
                }
            }
        }
        
        return count == numCourses;
    }
}