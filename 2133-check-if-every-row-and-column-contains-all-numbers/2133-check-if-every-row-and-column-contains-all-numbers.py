class Solution:
    def checkValid(self, matrix):
        n = len(matrix)
        return all(len(set(row)) == n for row in chain(matrix, zip(*matrix)))
