import java.util.*;
class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    boolean isEnd = false;
}
class StreamChecker {
    TrieNode root;
    Deque<Character> stream;
    public StreamChecker(String[] words) {
        root = new TrieNode();
        stream = new ArrayDeque<>();
        for (String w : words) {
            TrieNode node = root;
            for (int i = w.length()-1; i >= 0; i--) {
                char c = w.charAt(i);
                if (!node.children.containsKey(c)) node.children.put(c, new TrieNode());
                node = node.children.get(c);
            }
            node.isEnd = true;
        }
    }
    public boolean query(char letter) {
        stream.addFirst(letter);
        TrieNode node = root;
        for (char c : stream) {
            node = node.children.get(c);
            if (node == null) return false;
            if (node.isEnd) return true;
        }
        return false;
    }
}
