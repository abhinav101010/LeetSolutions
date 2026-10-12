from typing import List

class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        ans = [0] * n
        stack = []
        
        for log in logs:
            fid, event, ts = log.split(':')
            fid, ts = int(fid), int(ts)
            if event == 'start':
                if stack:
                    ans[stack[-1]] += ts - prev_ts
                stack.append(fid)
                prev_ts = ts
            else:
                ans[stack.pop()] += ts - prev_ts + 1
                prev_ts = ts + 1
        
        return ans