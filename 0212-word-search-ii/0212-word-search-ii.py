from typing import List

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # Build trie
        root = {}
        for word in words:
            node = root
            for c in word:
                if c not in node:
                    node[c] = {}
                node = node[c]
            node['#'] = word
        
        m, n = len(board), len(board[0])
        result = []
        
        def dfs(i, j, node):
            c = board[i][j]
            if c not in node:
                return
            
            node = node[c]
            if '#' in node:
                result.append(node['#'])
                del node['#']  # Avoid duplicates
            
            board[i][j] = '#'  # Mark visited
            for di, dj in [(0,1), (0,-1), (1,0), (-1,0)]:
                ni, nj = i + di, j + dj
                if 0 <= ni < m and 0 <= nj < n and board[ni][nj] != '#':
                    dfs(ni, nj, node)
            board[i][j] = c  # Restore
        
        for i in range(m):
            for j in range(n):
                dfs(i, j, root)
        
        return result