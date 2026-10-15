class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        def digit_count(x):
            cnt = [0]*10
            while x:
                cnt[x%10] += 1
                x //= 10
            return tuple(cnt)
        target = digit_count(n)
        for i in range(31):  # 2^30 > 1e9
            if digit_count(1<<i) == target:
                return True
        return False
