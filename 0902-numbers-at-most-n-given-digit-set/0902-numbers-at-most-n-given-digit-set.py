class Solution:
    def atMostNGivenDigitSet(self, D: list[str], N: int) -> int:
        S = str(N)
        L = len(S)
        d = len(D)
        # count numbers with length < L
        ans = 0
        for i in range(1, L):
            ans += d ** i
        # DP for same length
        i = 0
        while i < L:
            # count digits less than S[i]
            num_less = sum(1 for digit in D if digit < S[i])
            ans += num_less * (d ** (L - i - 1))
            if S[i] not in D:
                break
            i += 1
        else:
            # if all digits matched, include N itself
            ans += 1
        return ans
