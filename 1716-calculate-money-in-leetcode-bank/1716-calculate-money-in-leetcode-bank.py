class Solution:
    def totalMoney(self, n: int) -> int:
        weeks = n // 7
        days = n % 7

        total = 0

        for week in range(weeks):
            start = week + 1
            total += (start + start + 6) * 7 // 2
            
        start = weeks + 1
        for day in range(days):
            total += start + day

        return total