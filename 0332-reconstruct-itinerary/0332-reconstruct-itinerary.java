import java.util.*;

class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        Map<String, PriorityQueue<String>> graph = new HashMap<>();
        for (List<String> ticket : tickets) {
            graph.computeIfAbsent(ticket.get(0), k -> new PriorityQueue<>()).add(ticket.get(1));
        }
        
        List<String> route = new ArrayList<>();
        dfs("JFK", graph, route);
        Collections.reverse(route);
        return route;
    }
    
    private void dfs(String airport, Map<String, PriorityQueue<String>> graph, List<String> route) {
        PriorityQueue<String> pq = graph.get(airport);
        while (pq != null && !pq.isEmpty()) {
            dfs(pq.poll(), graph, route);
        }
        route.add(airport);
    }
}