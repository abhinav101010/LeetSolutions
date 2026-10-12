import java.util.*;

class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, List<Pair<String, Double>>> graph = new HashMap<>();
        for (int i = 0; i < equations.size(); i++) {
            String a = equations.get(i).get(0);
            String b = equations.get(i).get(1);
            double val = values[i];
            graph.computeIfAbsent(a, k -> new ArrayList<>()).add(new Pair<>(b, val));
            graph.computeIfAbsent(b, k -> new ArrayList<>()).add(new Pair<>(a, 1.0 / val));
        }
        
        double[] result = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            result[i] = bfs(queries.get(i).get(0), queries.get(i).get(1), graph);
        }
        return result;
    }
    
    private double bfs(String start, String end, Map<String, List<Pair<String, Double>>> graph) {
        if (!graph.containsKey(start) || !graph.containsKey(end)) return -1.0;
        if (start.equals(end)) return 1.0;
        
        Set<String> visited = new HashSet<>();
        Queue<Pair<String, Double>> queue = new LinkedList<>();
        queue.offer(new Pair<>(start, 1.0));
        visited.add(start);
        
        while (!queue.isEmpty()) {
            Pair<String, Double> curr = queue.poll();
            String node = curr.getKey();
            double val = curr.getValue();
            
            if (node.equals(end)) return val;
            
            for (Pair<String, Double> nei : graph.get(node)) {
                if (!visited.contains(nei.getKey())) {
                    visited.add(nei.getKey());
                    queue.offer(new Pair<>(nei.getKey(), val * nei.getValue()));
                }
            }
        }
        return -1.0;
    }
    
    static class Pair<K, V> {
        private K key;
        private V value;
        public Pair(K key, V value) { this.key = key; this.value = value; }
        public K getKey() { return key; }
        public V getValue() { return value; }
    }
}