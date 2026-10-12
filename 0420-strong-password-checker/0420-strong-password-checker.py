class Solution:
    def strongPasswordChecker(self, password: str) -> int:
        n = len(password)
        missing_lower = 1
        missing_upper = 1
        missing_digit = 1
        
        for c in password:
            if c.islower():
                missing_lower = 0
            elif c.isupper():
                missing_upper = 0
            elif c.isdigit():
                missing_digit = 0
        
        missing_types = missing_lower + missing_upper + missing_digit
        
        if n < 6:
            return max(6 - n, missing_types)
        
        replace = 0
        one = two = 0
        i = 2
        while i < n:
            if password[i] == password[i-1] == password[i-2]:
                length = 2
                while i < n and password[i] == password[i-1]:
                    length += 1
                    i += 1
                replace += length // 3
                if length % 3 == 0:
                    one += 1
                elif length % 3 == 1:
                    two += 1
            else:
                i += 1
        
        if n <= 20:
            return max(missing_types, replace)
        
        delete = n - 20
        replace -= min(delete, one)
        replace -= min(max(delete - one, 0), two * 2) // 2
        replace -= max(delete - one - 2 * two, 0) // 3
        
        return delete + max(missing_types, replace)