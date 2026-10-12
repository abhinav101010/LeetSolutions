class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        numbers = set()
        current = ""

        for ch in word:
            if ch.isdigit():
                current += ch
            else:
                if current:
                    numbers.add(int(current))
                    current = ""

        # Handle a number at the end of the string
        if current:
            numbers.add(int(current))

        return len(numbers)