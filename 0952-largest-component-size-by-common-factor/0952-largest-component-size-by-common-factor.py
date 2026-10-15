class Solution:
    def largestComponentSize(self, A: list[int]) -> int:
        n = len(A)
        maxA = max(A)
        parent = list(range(maxA + 1))
        size = [1] * (maxA + 1)
        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        def union(x, y):
            rx, ry = find(x), find(y)
            if rx == ry:
                return
            if size[rx] < size[ry]:
                rx, ry = ry, rx
            parent[ry] = rx
            size[rx] += size[ry]
        # sieve for primes up to maxA
        # For each number, get its prime factors and union with first occurrence of that prime
        prime_to_index = {}
        for num in A:
            x = num
            # factorize
            t = 2
            while t * t <= x:
                if x % t == 0:
                    # t is a prime factor
                    if t not in prime_to_index:
                        prime_to_index[t] = num
                    else:
                        union(num, prime_to_index[t])
                    while x % t == 0:
                        x //= t
                t += 1 if t == 2 else 2  # skip even numbers after 2
            if x > 1:
                # x is prime
                if x not in prime_to_index:
                    prime_to_index[x] = num
                else:
                    union(num, prime_to_index[x])
        # count component sizes for numbers in A
        count = {}
        for num in A:
            root = find(num)
            count[root] = count.get(root, 0) + 1
        return max(count.values())
