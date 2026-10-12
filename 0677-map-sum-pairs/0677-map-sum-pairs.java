import java.util.*;

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    int val = 0;
}

class MapSum {
    TrieNode root = new TrieNode();
    
    public void insert(String key, int val) {
        TrieNode node = root;
        for (char c : key.toCharArray()) {
            node.children.putIfAbsent(c, new TrieNode());
            node = node.children.get(c);
        }
        node.val = val;
    }
    
    public int sum(String prefix) {
        TrieNode node = root;
        for (char c : prefix.toCharArray()) {
            if (!node.children.containsKey(c)) return 0;
            node = node.children.get(c);
        }
        return dfs(node);
    }
    
    private int dfs(TrieNode node) {
        int s = node.val;
        for (TrieNode child : node.children.values()) {
            s += dfs(child);
        }
        return s;
    }
}