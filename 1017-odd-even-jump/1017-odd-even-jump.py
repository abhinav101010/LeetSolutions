class Solution:
    def oddEvenJumps(self, arr):
        n = len(arr)
        # build next higher index
        indices = sorted(range(n), key=lambda i: (arr[i], i))
        next_higher = [0] * n
        stack = []
        for i in indices:
            while stack and i > stack[-1]:
                next_higher[stack.pop()] = i
            stack.append(i)
        # next lower
        indices = sorted(range(n), key=lambda i: (-arr[i], i))
        next_lower = [0] * n
        stack = []
        for i in indices:
            while stack and i > stack[-1]:
                next_lower[stack.pop()] = i
            stack.append(i)
        odd = [False]*n; even = [False]*n
        odd[-1] = even[-1] = True
        for i in range(n-2, -1, -1):
            odd[i] = even[next_higher[i]] if next_higher[i] else False
            even[i] = odd[next_lower[i]] if next_lower[i] else False
        return sum(odd)
