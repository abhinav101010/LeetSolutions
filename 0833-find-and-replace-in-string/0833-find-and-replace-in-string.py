class Solution:
    def findReplaceString(self, s: str, indices: list[int], sources: list[str], targets: list[str]) -> str:
        n = len(s)
        # map index to (source, target) if matches
        matches = {}
        for idx, src, tgt in zip(indices, sources, targets):
            if s.startswith(src, idx):
                matches[idx] = (src, tgt)
        res = []
        i = 0
        while i < n:
            if i in matches:
                src, tgt = matches[i]
                res.append(tgt)
                i += len(src)
            else:
                res.append(s[i])
                i += 1
        return ''.join(res)
