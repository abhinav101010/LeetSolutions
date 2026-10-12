class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        lines = 1
        pixels = 0

        for c in s:
            width = widths[ord(c) - ord('a')]

            if pixels + width > 100:
                lines += 1
                pixels = width
            else:
                pixels += width

        return [lines, pixels]