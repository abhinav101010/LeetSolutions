import java.util.*;

class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        TrieNode root = new TrieNode();
        for (String word : words) {
            TrieNode node = root;
            for (char c : word.toCharArray()) {
                int idx = c - 'a';
                if (node.children[idx] == null) {
                    node.children[idx] = new TrieNode();
                }
                node = node.children[idx];
            }
            node.word = word;
        }
        
        int m = board.length, n = board[0].length;
        List<String> result = new ArrayList<>();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, result);
            }
        }
        
        return result;
    }
    
    private void dfs(char[][] board, int i, int j, TrieNode node, List<String> result) {
        char c = board[i][j];
        if (c == '#' || node.children[c - 'a'] == null) return;
        
        node = node.children[c - 'a'];
        if (node.word != null) {
            result.add(node.word);
            node.word = null; // Avoid duplicates
        }
        
        board[i][j] = '#';
        int[][] dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (int[] dir : dirs) {
            int ni = i + dir[0], nj = j + dir[1];
            if (ni >= 0 && ni < board.length && nj >= 0 && nj < board[0].length && board[ni][nj] != '#') {
                dfs(board, ni, nj, node, result);
            }
        }
        board[i][j] = c;
    }
    
    private static class TrieNode {
        TrieNode[] children;
        String word;
        TrieNode() {
            children = new TrieNode[26];
            word = null;
        }
    }
}