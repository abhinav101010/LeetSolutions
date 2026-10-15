class Solution:
    def rectangleArea(self, rectangles: list[list[int]]) -> int:
        MOD = 10**9 + 7
        events = []  # (x, type, y1, y2)
        ys = set()
        for x1, y1, x2, y2 in rectangles:
            events.append((x1, 1, y1, y2))
            events.append((x2, -1, y1, y2))
            ys.add(y1)
            ys.add(y2)
        ys = sorted(ys)
        y_to_idx = {v:i for i,v in enumerate(ys)}
        # count per segment between ys[i] and ys[i+1]
        cnt = [0] * (len(ys)-1)
        def add_interval(y1, y2, delta):
            i = y_to_idx[y1]
            j = y_to_idx[y2]
            for k in range(i, j):
                cnt[k] += delta
        def covered_length():
            total = 0
            for i in range(len(cnt)):
                if cnt[i] > 0:
                    total += ys[i+1] - ys[i]
            return total
        events.sort()
        ans = 0
        prev_x = events[0][0]
        for x, typ, y1, y2 in events:
            dx = x - prev_x
            if dx:
                ans = (ans + dx * covered_length()) % MOD
            prev_x = x
            add_interval(y1, y2, typ)
        return ans
