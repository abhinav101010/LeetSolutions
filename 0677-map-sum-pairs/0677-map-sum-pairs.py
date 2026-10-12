class MapSum:
    def __init__(self):
        self.trie = {}
        
    def insert(self, key: str, val: int) -> None:
        node = self.trie
        for c in key:
            if c not in node:
                node[c] = {}
            node = node[c]
        node['#'] = val
        
    def sum(self, prefix: str) -> int:
        node = self.trie
        for c in prefix:
            if c not in node:
                return 0
            node = node[c]
        
        def dfs(n):
            s = 0
            for k, v in n.items():
                if k == '#':
                    s += v
                else:
                    s += dfs(v)
            return s
        
        return dfs(node)