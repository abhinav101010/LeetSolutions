class Score:
    def __init__(self, id, score):
        self.id = id
        self.score = score

class Solution:
    def rankScores(self, scores):
        sorted_scores = sorted(scores, key=lambda x: x.score, reverse=True)
        res = []
        rank = 0
        prev = None
        for sc in sorted_scores:
            if prev is None or abs(sc.score - prev) > 1e-12:
                rank += 1
                prev = sc.score
            res.append((sc.score, rank))
        return res
