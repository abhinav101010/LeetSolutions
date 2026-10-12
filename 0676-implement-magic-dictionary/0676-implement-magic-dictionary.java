import java.util.*;

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    boolean isEnd = false;
}

class MagicDictionary {
    TrieNode root = new TrieNode();
    
    public void buildDict(String[] dictionary) {
        for (String word : dictionary) {
            TrieNode node = root;
            for (char c : word.toCharArray()) {
                node.children.putIfAbsent(c, new TrieNode());
                node = node.children.get(c);
            }
            node.isEnd = true;
        }
    }
    
    public boolean search(String searchWord) {
        return dfs(root, 0, false, searchWord);
    }
    
    private boolean dfs(TrieNode node, int idx, boolean changed, String word) {
        if (idx == word.length()) return node.isEnd && changed;
        char c = word.charAt(idx);
        for (Map.Entry<Character, TrieNode> e : node.children.entrySet()) {
            char childC = e.getKey();
            TrieNode childNode = e.getValue();
            if (c == childC) {
                if (dfs(childNode, idx + 1, changed, word)) return true;
            } else if (!changed) {
                if (dfs(childNode, idx + 1, true, word)) return true;
            }
        }
        return false;
    }
}