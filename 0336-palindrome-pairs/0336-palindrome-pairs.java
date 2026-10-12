import java.util.*;

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    int wordId = -1;
    List<Integer> palindromeSuffixes = new ArrayList<>();
}

class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        TrieNode root = new TrieNode();
        
        for (int i = 0; i < words.length; i++) {
            TrieNode node = root;
            String word = words[i];
            for (int j = word.length() - 1; j >= 0; j--) {
                char c = word.charAt(j);
                if (!node.children.containsKey(c)) {
                    node.children.put(c, new TrieNode());
                }
                String prefix = word.substring(0, j + 1);
                if (isPalindrome(prefix)) {
                    node.palindromeSuffixes.add(i);
                }
                node = node.children.get(c);
            }
            node.wordId = i;
        }
        
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            TrieNode node = root;
            String word = words[i];
            for (int j = 0; j < word.length(); j++) {
                if (node.wordId != -1 && node.wordId != i) {
                    String suffix = word.substring(j);
                    if (isPalindrome(suffix)) {
                        result.add(Arrays.asList(i, node.wordId));
                    }
                }
                char c = word.charAt(j);
                if (!node.children.containsKey(c)) break;
                node = node.children.get(c);
            }
            if (node.wordId != -1 && node.wordId != i) {
                result.add(Arrays.asList(i, node.wordId));
            }
            for (int pid : node.palindromeSuffixes) {
                if (pid != i) result.add(Arrays.asList(i, pid));
            }
        }
        
        return result;
    }
    
    private boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) return false;
        }
        return true;
    }
}