class Solution:
    def lenLongestFibSubseq(self, arr: list[int]) -> int:
        s = set(arr)
        n = len(arr)
        best = 0
        for i in range(n):
            for j in range(i+1, n):
                a = arr[i]
                b = arr[j]
                length = 2
                while a + b in s:
                    a, b = b, a + b
                    length += 1
                if length > best:
                    best = length
        return best if best >= 3 else 0
