class Solution:
    def superpalindromesInRange(self, left: str, right: str) -> int:
        L = int(left)
        R = int(right)
        # generate palindromes
        def is_pal(x):
            s = str(x)
            return s == s[::-1]
        count = 0
        # length of half up to 5 because (10^5)^2 = 10^10 > 10^9
        # Actually we need to consider odd and even length palindromes
        # We'll generate by constructing root
        # odd length
        for k in range(1, 10000):  # up to 5 digits
            s = str(k)
            # odd length palindrome
            p_odd = int(s + s[-2::-1])
            square = p_odd * p_odd
            if square > R:
                break
            if square >= L and is_pal(square):
                count += 1
            # even length palindrome
            p_even = int(s + s[::-1])
            square = p_even * p_even
            if square > R:
                # we cannot break here because odd may still be smaller? but we continue loops
                pass
            else:
                if square >= L and is_pal(square):
                    count += 1
        return count
