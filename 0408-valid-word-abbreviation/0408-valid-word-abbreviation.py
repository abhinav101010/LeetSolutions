class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        i = j = 0
        while i < len(word) and j < len(abbr):
            if word[i] == abbr[j]:
                i += 1
                j += 1
                continue
            if not abbr[j].isdigit() or abbr[j] == '0':
                return False
            k = j
            while k < len(abbr) and abbr[k].isdigit():
                k += 1
            num = int(abbr[j:k])
            i += num
            j = k
        return i == len(word) and j == len(abbr)