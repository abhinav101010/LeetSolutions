class Solution:
    def oddEvenJumps(self, arr):
        n = len(arr)
        # next higher
        sorted_idx = sorted(range(n), key=lambda i: (arr[i], i))
        next_higher = [0] * n
        stack = []
        for i in sorted_idx:
            while stack and i > stack[-1]:
                next_higher[stack.pop()] = i
            stack.append(i)
        # next lower
        sorted_idx = sorted(range(n), key=lambda i: (-arr[i], i))
        next_lower = [0] * n
        stack = []
        for i in sorted_idx:
            while stack and i > stack[-1]:
                next_lower[stack.pop()] = i
            stack.append(i)
        # dp
        odd = [False] * n
        even = [False] * n
        odd[-1] = even[-1] = True
        for i in range(n-2, -1, -1):
            odd[i] = even[next_higher[i]]
            even[i] = odd[next_lower[i]]
        return sum(odd)
