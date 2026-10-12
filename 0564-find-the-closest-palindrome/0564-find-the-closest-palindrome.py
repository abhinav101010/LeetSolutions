class Solution:
    def nearestPalindromic(self, n: str) -> str:
        if n == "1":
            return "0"
        
        length = len(n)
        candidates = set()
        
        # 10^length + 1 and 10^(length-1) - 1
        candidates.add(str(10**length + 1))
        candidates.add(str(10**(length - 1) - 1))
        
        prefix = int(n[:(length + 1) // 2])
        for i in [prefix - 1, prefix, prefix + 1]:
            if length % 2 == 0:
                pal = str(i) + str(i)[::-1]
            else:
                pal = str(i) + str(i)[:-1][::-1]
            candidates.add(pal)
        
        candidates.discard(n)
        
        min_diff = float('inf')
        result = None
        target = int(n)
        
        for cand in candidates:
            diff = abs(int(cand) - target)
            if diff < min_diff or (diff == min_diff and int(cand) < int(result)):
                min_diff = diff
                result = cand
        
        return result