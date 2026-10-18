from typing import List


class SurveyLog:
    def __init__(self, question_id: int, action: str):
        self.question_id = question_id
        self.action = action


class Solution:
    def highestAnswerRate(self, log: List[SurveyLog]) -> List[List[str]]:
        q = {}
        for l in log:
            if l.question_id not in q:
                q[l.question_id] = [0, 0]
            if l.action == "answer":
                q[l.question_id][0] += 1
            elif l.action == "show":
                q[l.question_id][1] += 1
        rows = []
        for qid, (ans, sh) in q.items():
            if ans > 0:
                rate = 0.0 if sh == 0 else ans / sh
                rows.append((qid, rate))
        rows.sort(key=lambda x: (-x[1], x[0]))
        if not rows:
            return []
        return [[str(rows[0][0])]]
