import java.util.*;

class WordDictionary {
    private TrieNode root;
    
    public WordDictionary() {
        root = new TrieNode();
    }
    
    public void addWord(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new TrieNode();
            }
            node = node.children[idx];
        }
        node.isEnd = true;
    }
    
    public boolean search(String word) {
        return dfs(root, word, 0);
    }
    
    private boolean dfs(TrieNode node, String word, int i) {
        if (i == word.length()) return node.isEnd;
        
        char c = word.charAt(i);
        if (c == '.') {
            for (TrieNode child : node.children) {
                if (child != null && dfs(child, word, i + 1)) {
                    return true;
                }
            }
            return false;
        }
        
        int idx = c - 'a';
        if (node.children[idx] == null) return false;
        return dfs(node.children[idx], word, i + 1);
    }
    
    private static class TrieNode {
        TrieNode[] children;
        boolean isEnd;
        
        TrieNode() {
            children = new TrieNode[26];
            isEnd = false;
        }
    }
}