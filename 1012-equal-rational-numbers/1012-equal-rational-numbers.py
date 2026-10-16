from fractions import Fraction
class Solution:
    def isRationalEqual(self, s, t):
        def f(x):
            if '.' not in x:
                return Fraction(x)
            i = x.index('.')
            intp = x[:i]
            frac = x[i+1:]
            if '(' not in frac:
                nonrep = frac
                rep = ''
            else:
                j = frac.index('(')
                nonrep = frac[:j]
                rep = frac[j+1:len(frac)-1]
            val = Fraction(intp) if intp else Fraction(0)
            if nonrep:
                val += Fraction(int(nonrep), 10**len(nonrep)) if nonrep else Fraction(0)
            if rep:
                repd = 10**len(nonrep) * (10**len(rep) - 1)
                val += Fraction(int(rep), repd)
            return val
        return f(s) == f(t)
