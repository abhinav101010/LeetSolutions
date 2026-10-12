from typing import List

class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        n = len(nums)
        
        def next_idx(i):
            return (i + nums[i]) % n
        
        for i in range(n):
            if nums[i] == 0:
                continue
            slow, fast = i, i
            direction = nums[i] > 0
            
            while True:
                slow = next_idx(slow)
                fast = next_idx(fast)
                if fast != -1:
                    fast = next_idx(fast)
                
                if slow == -1 or fast == -1 or nums[slow] * nums[i] <= 0 or nums[fast] * nums[i] <= 0:
                    break
                
                if slow == fast:
                    if slow == next_idx(slow):
                        break
                    return True
            
            # Mark visited
            slow = i
            while nums[slow] * nums[i] > 0:
                nxt = next_idx(slow)
                nums[slow] = 0
                slow = nxt
        
        return False