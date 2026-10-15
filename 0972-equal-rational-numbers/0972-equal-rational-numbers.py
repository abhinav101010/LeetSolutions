from fractions import Fraction
class Solution:
    def isRationalEqual(self, s: str, t: str) -> bool:
        return self.toFraction(s) == self.toFraction(t)
    def toFraction(self, s: str) -> Fraction:
        if '(' not in s:
            # no repeating part
            if '.' not in s:
                return Fraction(int(s), 1)
            else:
                int_part, frac_part = s.split('.')
                if frac_part == '':
                    return Fraction(int(int_part), 1)
                else:
                    # terminating decimal
                    return Fraction(int(int_part) * pow(10, len(frac_part)) + int(frac_part), pow(10, len(frac_part)))
        else:
            # has repeating part
            # split into integer part and rest
            int_part, rest = s.split('.')
            # rest has format non_repeating(repeating)
            p = rest.index('(')
            non_rep = rest[:p]
            rep = rest[p+1:-1]  # exclude ')'
            a = len(non_rep)
            b = len(rep)
            # compute numerator and denominator
            # value = int_part + (non_rep as int)/10^a + (rep as int)/(10^a * (10^b - 1))
            I = int(int_part) if int_part else 0
            N = int(non_rep) if non_rep else 0
            R = int(rep) if rep else 0
            denom = pow(10, a) * (pow(10, b) - 1)
            num = I * denom + N * (pow(10, b) - 1) + R
            return Fraction(num, denom)
