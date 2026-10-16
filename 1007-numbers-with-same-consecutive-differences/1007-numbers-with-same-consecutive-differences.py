class Solution:
    def numsSameConsecDiff(self, n, k):
        if n == 1:
            return [i for i in range(10)]
        from collections import deque
        q = deque(range(1,10))  # first digit cannot be 0
        for _ in range(n-1):
            size = len(q)
            for _ in range(size):
                num = q.popleft()
                tail = num % 10
                next_digits = set([tail + k, tail - k])
                for d in next_digits:
                    if 0 <= d <= 9:
                        q.append(num * 10 + d)
        return list(q)
