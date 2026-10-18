import java.util.*;

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    int hot = 0; // negative for sorting ascending
    boolean isEnd = false;
}

class AutocompleteSystem {
    private TrieNode root;
    private TrieNode node;
    private String prefix;

    public AutocompleteSystem(String[] sentences, int[] times) {
        root = new TrieNode();
        node = root;
        prefix = "";
        for (int i = 0; i < sentences.length; i++) {
            add(sentences[i], times[i]);
        }
    }

    public void add(String sentence, int times) {
        TrieNode cur = root;
        for (char ch : sentence.toCharArray()) {
            cur.children.putIfAbsent(ch, new TrieNode());
            cur = cur.children.get(ch);
        }
        cur.isEnd = true;
        cur.hot -= times;
    }

    private void dfs(TrieNode node, String path, List<Map.Entry<Integer, String>> list) {
        if (node.isEnd) {
            list.add(new AbstractMap.SimpleEntry<>(node.hot, path));
        }
        for (Map.Entry<Character, TrieNode> entry : node.children.entrySet()) {
            dfs(entry.getValue(), path + entry.getKey(), list);
        }
    }

    public List<String> input(char c) {
        if (c == '#') {
            add(prefix, 1);
            node = root;
            prefix = "";
            return Collections.emptyList();
        }
        prefix += c;
        if (node == null) {
            return Collections.emptyList();
        }
        if (!node.children.containsKey(c)) {
            node = null;
            return Collections.emptyList();
        }
        node = node.children.get(c);
        List<Map.Entry<Integer, String>> list = new ArrayList<>();
        dfs(node, prefix, list);
        Collections.sort(list, Comparator.comparingInt(Map.Entry::getKey));
        List<String> res = new ArrayList<>();
        for (int i = 0; i < Math.min(3, list.size()); i++) {
            res.add(list.get(i).getValue());
        }
        return res;
    }
}
