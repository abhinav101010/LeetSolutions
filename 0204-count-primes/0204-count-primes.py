class Solution:
    def countPrimes(self, n: int) -> int:
        # count = 0
        # for i in range(2,n):
        #     isPrime = True
        #     for j in range(2,i):
        #         if i%j == 0:
        #             isPrime = False
        #             break
        #     if isPrime: count+=1
        # return count

# Both self thought and implemented logic
        # if n <= 2: return 0

        # count = list(range(2, n))
        # for num in count[:]:
        #     i = 2
        #     while num * i < n:
        #         if num * i in count:
        #             count.remove(num * i)
        #         i += 1

        # return len(count)

        if n <= 2:
            return 0
        is_prime = [True] * n
        is_prime[0] = is_prime[1] = False
        for i in range(2, int(n ** 0.5) + 1):
            if is_prime[i]:
                for j in range(i * i, n, i):
                    is_prime[j] = False
        return sum(is_prime)