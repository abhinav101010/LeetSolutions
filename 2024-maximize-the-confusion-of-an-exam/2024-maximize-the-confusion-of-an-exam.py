class Solution:
    def maxConsecutiveAnswers(self, answerKey, k):
        def f(c):
            cnt = l = 0
            for ch in answerKey:
                cnt += ch == c
                if cnt > k:
                    cnt -= answerKey[l] == c
                    l += 1
            return len(answerKey) - l

        return max(f("T"), f("F"))
