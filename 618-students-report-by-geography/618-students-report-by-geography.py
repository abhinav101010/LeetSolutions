class Student:
    def __init__(self, name, continent):
        self.name = name
        self.continent = continent

class Solution:
    def report(self, students):
        america = []
        asia = []
        europe = []
        for s in students:
            if s.continent == 'America':
                america.append(s.name)
            elif s.continent == 'Asia':
                asia.append(s.name)
            elif s.continent == 'Europe':
                europe.append(s.name)
        america.sort()
        asia.sort()
        europe.sort()
        maxn = max(len(america), len(asia), len(europe))
        res = []
        for i in range(maxn):
            res.append((
                america[i] if i < len(america) else '',
                asia[i] if i < len(asia) else '',
                europe[i] if i < len(europe) else '',
            ))
        return res
