/**
 * Definition for a Node.
 * class Node {
 *     public int val;
 *     public List<Node> neighbors;
 *     public Node() {
 *         val = 0;
 *         neighbors = new ArrayList<Node>();
 *     }
 *     public Node(int _val) {
 *         val = _val;
 *         neighbors = new ArrayList<Node>();
 *     }
 *     public Node(int _val, ArrayList<Node> _neighbors) {
 *         val = _val;
 *         neighbors = _neighbors;
 *     }
 * }
 */
import java.util.*;

class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) return null;
        
        Map<Node, Node> visited = new HashMap<>();
        return dfs(node, visited);
    }
    
    private Node dfs(Node original, Map<Node, Node> visited) {
        if (visited.containsKey(original)) {
            return visited.get(original);
        }
        
        Node clone = new Node(original.val);
        visited.put(original, clone);
        
        for (Node neighbor : original.neighbors) {
            clone.neighbors.add(dfs(neighbor, visited));
        }
        
        return clone;
    }
}