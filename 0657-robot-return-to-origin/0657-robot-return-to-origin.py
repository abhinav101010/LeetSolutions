class Solution:
    def judgeCircle(self, moves: str) -> bool:
# My another useless thinking, cause i didnt read the question properly ;-;
        # for c in moves:
        #     if c == "U" and "D" not in moves:
        #         return False
        #     if c == "D" and "U" not in moves:
        #         return False
        #     if c == "L" and "R" not in moves:
        #         return False
        #     if c == "R" and "L" not in moves:
        #         return False
        # return True

        # x = 0
        # y = 0
        # for c in moves:
        #     if c == "U": y+=1
        #     if c == "D": y-=1
        #     if c == "R": x+=1
        #     if c == "L": x-=1
        # return x == 0 and y == 0

        if moves.count('L')==moves.count('R') and moves.count('U') == moves.count('D'):
            return True
        else:
            return False