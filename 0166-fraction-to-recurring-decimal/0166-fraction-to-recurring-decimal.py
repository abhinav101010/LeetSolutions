class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"

        ans = []

        # Handle sign
        if (numerator < 0) ^ (denominator < 0):
            ans.append("-")

        numerator = abs(numerator)
        denominator = abs(denominator)

        # Integer part
        ans.append(str(numerator // denominator))
        remainder = numerator % denominator

        if remainder == 0:
            return "".join(ans)

        ans.append(".")

        # remainder -> index in ans
        seen = {}

        while remainder:
            if remainder in seen:
                idx = seen[remainder]
                ans.insert(idx, "(")
                ans.append(")")
                break

            seen[remainder] = len(ans)

            remainder *= 10
            ans.append(str(remainder // denominator))
            remainder %= denominator

        return "".join(ans)