class Solution:
    def decodeAtIndex(self, s: str, k: int) -> str:
        length = 0
        for ch in s:
            if ch.isdigit():
                length *= int(ch)
            else:
                length += 1
        for ch in reversed(s):
            k %= length
            if k == 0 and ch.isalpha():
                return ch
            if ch.isdigit():
                length //= int(ch)
            else:
                length -= 1
        return ""
