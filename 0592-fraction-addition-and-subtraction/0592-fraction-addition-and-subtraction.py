import re
from math import gcd

class Solution:
    def fractionAddition(self, expression: str) -> str:
        num = 0
        den = 1
        
        tokens = re.findall(r'([+-]?\d+)/(\d+)', expression)
        
        for a_str, b_str in tokens:
            a = int(a_str)
            b = int(b_str)
            num = num * b + a * den
            den = den * b
            g = gcd(abs(num), den)
            num //= g
            den //= g
        
        return f"{num}/{den}"