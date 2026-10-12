class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        rows = []

        for i in range(len(mat)):
            rows.append((sum(mat[i]), i))

        rows.sort()

        return [i for count, i in rows[:k]]