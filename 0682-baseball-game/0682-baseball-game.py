class Solution:
    def calPoints(self, operations: List[str]) -> int:
        scores = []
        for opr in operations:
            if opr == "C":
                scores.pop()
                continue
            if opr == "D":
                scores.append(2*scores[-1])
                continue
            if opr == "+":
                scores.append(scores[-2]+scores[-1])
                continue
            scores.append(int(opr))
        return sum(scores)