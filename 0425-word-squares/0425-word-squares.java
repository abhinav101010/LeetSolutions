import java.util.*;

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    List<String> words = new ArrayList<>();
}

class Trie {
    TrieNode root = new TrieNode();
    public Trie(String[] words) {
        for (String w : words) {
            insert(w);
        }
    }
    private void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            node.children.putIfAbsent(c, new TrieNode());
            node = node.children.get(c);
            node.words.add(word);
        }
    }
    public List<String> startWith(String prefix) {
        TrieNode node = root;
        for (char c : prefix.toCharArray()) {
            if (!node.children.containsKey(c)) return new ArrayList<>();
            node = node.children.get(c);
        }
        return node.words;
    }
}

class Solution {
    private List<List<String>> res = new ArrayList<>();
    private int n;
    private Trie trie;
    
    public List<List<String>> wordSquares(String[] words) {
        if (words.length == 0) return res;
        n = words[0].length();
        trie = new Trie(words);
        backtrack(new ArrayList<>());
        return res;
    }
    
    private void backtrack(List<String> path) {
        if (path.size() == n) {
            res.add(new ArrayList<>(path));
            return;
        }
        int idx = path.size();
        StringBuilder prefix = new StringBuilder();
        for (String p : path) {
            prefix.append(p.charAt(idx));
        }
        for (String w : trie.startWith(prefix.toString())) {
            path.add(w);
            backtrack(path);
            path.remove(path.size() - 1);
        }
    }
}