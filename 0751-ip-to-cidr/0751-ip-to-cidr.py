from typing import List

class Solution:
    def ipToCIDR(self, ip: str, n: int) -> List[str]:
        def ip_to_int(ip):
            parts = list(map(int, ip.split('.')))
            return (parts[0] << 24) + (parts[1] << 16) + (parts[2] << 8) + parts[3]
        
        def int_to_ip(x):
            return f"{(x >> 24) & 255}.{(x >> 16) & 255}.{(x >> 8) & 255}.{x & 255}"
        
        def mask_to_prefix(mask):
            # mask is power of two
            return 32 - (int)(math.log2(mask))
        
        import math
        cur = ip_to_int(ip)
        ans = []
        while n > 0:
            # max size we can use is lowbit of cur, but not exceeding n
            lowbit = cur & -cur
            while lowbit > n:
                lowbit >>= 1
            # prefix length
            prefix = 32 - (int)(math.log2(lowbit))
            ans.append(int_to_ip(cur) + "/" + str(prefix))
            cur += lowbit
            n -= lowbit
        return ans
