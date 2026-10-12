class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        changed = True
        i = len(digits)-1
        while changed:
            changed = False
            digits[i]+=1
            if digits[i]%10 == 0:
                changed = True
                digits[i] = 0
                i-=1
                if i<0: 
                    digits.insert(0,0) 
                    i+=1
        return digits
        