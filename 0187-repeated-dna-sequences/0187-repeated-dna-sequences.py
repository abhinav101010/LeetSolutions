class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        count = {}
        result = []

        for i in range(len(s) - 9):
            sequence = s[i:i + 10]

            count[sequence] = count.get(sequence, 0) + 1

            if count[sequence] == 2:
                result.append(sequence)

        return result