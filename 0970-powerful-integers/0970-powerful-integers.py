class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> list[int]:
        if bound < 1:
            return []
        xs = []
        xi = 1
        while True:
            xs.append(xi)
            if x == 1:
                break
            xi *= x
            if xi > bound:
                break
        ys = []
        yi = 1
        while True:
            ys.append(yi)
            if y == 1:
                break
            yi *= y
            if yi > bound:
                break
        res = set()
        for a in xs:
            for b in ys:
                s = a + b
                if s <= bound:
                    res.add(s)
                else:
                    break
        return list(res)
