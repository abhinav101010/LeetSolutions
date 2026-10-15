class Solution:
    def nextClosestTime(self, time: str) -> str:
        allowed = set(time.replace(':', ''))
        h, m = map(int, time.split(':'))
        start = h * 60 + m
        for offset in range(1, 24*60+1):
            cand = (start + offset) % (24*60)
            hh = cand // 60
            mm = cand % 60
            cand_str = f"{hh:02d}:{mm:02d}"
            if set(cand_str.replace(':', '')) <= allowed:
                return cand_str
        return time  # fallback
