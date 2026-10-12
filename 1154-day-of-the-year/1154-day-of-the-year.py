class Solution:
    def dayOfYear(self, date: str) -> int:
        givenDate = date.split("-")

        days = [0, 31, 28, 31, 30, 31, 30,
                31, 31, 30, 31, 30, 31]

        year = int(givenDate[0])
        month = int(givenDate[1])
        day = int(givenDate[2])

        leap = year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)

        ans = sum(days[:month]) + day

        if leap and month > 2:
            ans += 1

        return ans