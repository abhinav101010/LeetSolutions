class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        d = deque(senate)
        count_r = count_d = 0
        while d:
            p = d.popleft()
            if p == 'R':
                count_r += 1
                if count_d > 0:
                    count_d -= 1
                    continue
                else:
                    d.append(p)
            else:
                count_d += 1
                if count_r > 0:
                    count_r -= 1
                    continue
                else:
                    d.append(p)
        return 'Radiant' if 'R' in d or count_r > 0 else 'Dire'