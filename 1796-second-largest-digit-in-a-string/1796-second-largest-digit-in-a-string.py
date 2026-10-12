class Solution:
    def secondHighest(self, s: str) -> int:
        digits = set()

        for ch in s:
            if ch.isdigit():
                digits.add(int(ch))

        if len(digits) < 2:
            return -1

        digits.remove(max(digits))

        return max(digits)