class Solution:
    def reformatNumber(self, number: str) -> str:
        digits = number.replace(" ", "").replace("-", "")
        
        ans = []
        i = 0
        n = len(digits)

        while n - i > 4:
            ans.append(digits[i:i + 3])
            i += 3

        remaining = n - i

        if remaining == 4:
            ans.append(digits[i:i + 2])
            ans.append(digits[i + 2:i + 4])
        else:
            ans.append(digits[i:])

        return "-".join(ans)