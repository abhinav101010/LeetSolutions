class Solution:
    def primePalindrome(self, n: int) -> int:
        def is_prime(x):
            if x < 2:
                return False
            if x == 2:
                return True
            if x % 2 == 0:
                return False
            i = 3
            while i * i <= x:
                if x % i == 0:
                    return False
                i += 2
            return True
        # special case: 8 <= n <= 11 => 11
        if 8 <= n <= 11:
            return 11
        # generate palindromes with odd length
        # we can generate by taking first half and mirroring
        for length in range(1, 6):  # up to 5 digits half => palindrome up to 9 digits
            start = 10**(length-1)
            end = 10**length
            for x in range(start, end):
                s = str(x)
                pal = int(s + s[-2::-1])  # mirror without last digit
                if pal >= n and is_prime(pal):
                    return pal
        # fallback (should not happen)
        return -1
