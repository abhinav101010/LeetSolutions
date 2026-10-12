class Solution:
    def intToRoman(self, num: int) -> str:
        intRom = [
            [1000, "M"],
            [900, "CM"],
            [500, "D"],
            [400, "CD"],
            [100, "C"],
            [90, "XC"],
            [50, "L"],
            [40, "XL"],
            [10, "X"],
            [9, "IX"],
            [5, "V"],
            [4, "IV"],
            [1, "I"],
        ]

        ans = ""
        for a in intRom:
            while num>=a[0]:
                ans += (a[1])
                num-=a[0]
        return ans