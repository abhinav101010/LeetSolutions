class Solution:
    def numFriendRequests(self, ages: list[int]) -> int:
        cnt = [0] * 121
        for age in ages:
            cnt[age] += 1
        def request(a, b):
            if b <= 0.5 * a + 7:
                return False
            if b > a:
                return False
            if b > 100 and a < 100:
                return False
            return True
        ans = 0
        for a in range(1, 121):
            if cnt[a] == 0:
                continue
            for b in range(1, 121):
                if cnt[b] == 0:
                    continue
                if request(a, b):
                    if a == b:
                        ans += cnt[a] * (cnt[a] - 1)
                    else:
                        ans += cnt[a] * cnt[b]
        return ans
