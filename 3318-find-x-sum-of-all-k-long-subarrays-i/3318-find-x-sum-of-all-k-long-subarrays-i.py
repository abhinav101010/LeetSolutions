class Solution:
    def findXSum(self, nums, k, x) -> List[int]:
        def add(v):
            if cnt[v] == 0:
                return
            p = (cnt[v], v)
            if l and p > l[0]:
                nonlocal s
                s += p[0] * p[1]
                l.add(p)
            else:
                r.add(p)

        def remove(v):
            if cnt[v] == 0:
                return
            p = (cnt[v], v)
            if p in l:
                nonlocal s
                s -= p[0] * p[1]
                l.remove(p)
            else:
                r.remove(p)

        l = SortedList()
        r = SortedList()
        cnt = Counter()
        s = 0
        n = len(nums)
        ans = [0] * (n - k + 1)
        for i, v in enumerate(nums):
            remove(v)
            cnt[v] += 1
            add(v)
            j = i - k + 1
            if j < 0:
                continue
            while r and len(l) < x:
                p = r.pop()
                l.add(p)
                s += p[0] * p[1]
            while len(l) > x:
                p = l.pop(0)
                s -= p[0] * p[1]
                r.add(p)
            ans[j] = s

            remove(nums[j])
            cnt[nums[j]] -= 1
            add(nums[j])
        return ans
