class Solution:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        if n1 == 0:
            return 0
        
        s1_count = 0
        s2_count = 0
        index = 0
        recall = {}
        
        while s1_count < n1:
            s1_count += 1
            for ch in s1:
                if ch == s2[index]:
                    index += 1
                    if index == len(s2):
                        s2_count += 1
                        index = 0
            
            if index in recall:
                prev_s1_count, prev_s2_count = recall[index]
                pre_loop_s1 = prev_s1_count
                pre_loop_s2 = prev_s2_count
                in_loop_s1 = s1_count - prev_s1_count
                in_loop_s2 = s2_count - prev_s2_count
                
                if in_loop_s1 > 0:
                    remaining = n1 - pre_loop_s1
                    loops = remaining // in_loop_s1
                    s1_count = pre_loop_s1 + loops * in_loop_s1
                    s2_count = pre_loop_s2 + loops * in_loop_s2
            else:
                recall[index] = (s1_count, s2_count)
        
        return s2_count // n2