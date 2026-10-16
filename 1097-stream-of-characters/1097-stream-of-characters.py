class StreamChecker:
    def __init__(self, words):
        self.trie = {}
        self.stream = []
        for w in words:
            node = self.trie
            for c in w[::-1]:
                node = node.setdefault(c, {})
            node['#'] = True
    def query(self, letter):
        self.stream.append(letter)
        node = self.trie
        for c in reversed(self.stream):
            if '#' in node:
                return True
            if c not in node:
                return False
            node = node[c]
        return '#' in node
