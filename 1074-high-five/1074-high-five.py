from collections import defaultdict
class Solution:
    def highFive(self, items):
        scores = defaultdict(list)
        for sid, score in items:
            scores[sid].append(score)
        res = []
        for sid in scores:
            scores[sid].sort(reverse=True)
            res.append([sid, sum(scores[sid][:5])//5])
        res.sort(key=lambda x: x[0])
        return res
