import java.util.*;

class Solution {
    class TrieNode {
        Map<Character, TrieNode> children = new HashMap<>();
        boolean isEnd = false;
    }
    
    class Trie {
        TrieNode root = new TrieNode();
        void insert(String word) {
            TrieNode node = root;
            for (char c : word.toCharArray()) {
                node = node.children.computeIfAbsent(c, k -> new TrieNode());
            }
            node.isEnd = true;
        }
        String findRoot(String word) {
            TrieNode node = root;
            for (int i = 0; i < word.length(); i++) {
                char c = word.charAt(i);
                if (!node.children.containsKey(c)) return word;
                node = node.children.get(c);
                if (node.isEnd) return word.substring(0, i+1);
            }
            return word;
        }
    }
    
    public String replaceWords(List<String> dictionary, String sentence) {
        Trie trie = new Trie();
        for (String w : dictionary) trie.insert(w);
        StringBuilder sb = new StringBuilder();
        for (String w : sentence.split(" ")) {
            if (sb.length() > 0) sb.append(" ");
            sb.append(trie.findRoot(w));
        }
        return sb.toString();
    }
}