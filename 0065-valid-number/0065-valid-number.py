class Solution:
    def isNumber(self, s: str) -> bool:
        s = s.strip()
        if not s:
            return False
        
        i = 0
        n = len(s)
        is_numeric = False
        
        # Check sign
        if s[i] in '+-':
            i += 1
        
        # Scan digits before decimal
        while i < n and s[i].isdigit():
            i += 1
            is_numeric = True
        
        # Scan decimal point and digits after
        if i < n and s[i] == '.':
            i += 1
            while i < n and s[i].isdigit():
                i += 1
                is_numeric = True
        
        if not is_numeric:
            return False
        
        # Scan exponent
        if i < n and s[i] in 'eE':
            i += 1
            if i < n and s[i] in '+-':
                i += 1
            if i == n:
                return False
            exp_digits = False
            while i < n and s[i].isdigit():
                i += 1
                exp_digits = True
            if not exp_digits:
                return False
        
        return i == n