class Solution:
    def mergeSimilarItems(self, items1, items2):
        cnt = Counter()
        for v, w in chain(items1, items2):
            cnt[v] += w
        return [[v, w] for v, w in sorted(cnt.items())]
