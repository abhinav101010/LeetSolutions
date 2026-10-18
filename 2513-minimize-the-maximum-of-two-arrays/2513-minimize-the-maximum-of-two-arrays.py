class Solution:
    def minimizeSet(
        self, divisor1, divisor2, uniqueCnt1, uniqueCnt2) :
        def f(x):
            cnt1 = x // divisor1 * (divisor1 - 1) + x % divisor1
            cnt2 = x // divisor2 * (divisor2 - 1) + x % divisor2
            cnt = x // divisor * (divisor - 1) + x % divisor
            return (
                cnt1 >= uniqueCnt1
                and cnt2 >= uniqueCnt2
                and cnt >= uniqueCnt1 + uniqueCnt2
            )

        divisor = lcm(divisor1, divisor2)
        return bisect_left(range(10**10), True, key=f)
