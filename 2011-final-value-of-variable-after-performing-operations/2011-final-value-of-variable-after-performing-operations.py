class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        x = 0
        for oper in operations:
            x += 1 if oper == "X++" else 0
            x += 1 if oper == "++X" else 0
            x -= 1 if oper == "X--" else 0
            x -= 1 if oper == "--X" else 0
        return x