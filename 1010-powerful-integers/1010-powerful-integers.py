import math
class Solution:
    def powerfulIntegers(self, x, y, bound):
        if bound < 1:
            return []
        xs = []
        xi = 1
        while xi <= bound:
            xs.append(xi)
            if x == 1:
                break
            xi *= x
        ys = []
        yi = 1
        while yi <= bound:
            ys.append(yi)
            if y == 1:
                break
            yi *= y
        res = set()
        for a in xs:
            for b in ys:
                s = a + b
                if s <= bound:
                    res.add(s)
        return list(res)
