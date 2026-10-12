from collections import Counter, defaultdict

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t or len(s) < len(t):
            return ""
        
        target = Counter(t)
        required = len(target)
        
        left = 0
        formed = 0
        window_counts = defaultdict(int)
        
        ans = float('inf'), None, None  # length, left, right
        
        for right, char in enumerate(s):
            window_counts[char] += 1
            
            if char in target and window_counts[char] == target[char]:
                formed += 1
            
            while left <= right and formed == required:
                char = s[left]
                
                if right - left + 1 < ans[0]:
                    ans = (right - left + 1, left, right)
                
                window_counts[char] -= 1
                if char in target and window_counts[char] < target[char]:
                    formed -= 1
                
                left += 1
        
        return "" if ans[0] == float('inf') else s[ans[1]:ans[2] + 1]