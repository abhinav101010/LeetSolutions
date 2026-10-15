import java.math.BigInteger;
import java.util.*;
class Solution {
    public boolean isRationalEqual(String s, String t) {
        return toFraction(s).equals(toFraction(t));
    }
    private BigInteger gcd(BigInteger a, BigInteger b) {
        return b.equals(BigInteger.ZERO) ? a : gcd(b, a.mod(b));
    }
    private static class Fraction {
        BigInteger num, den;
        Fraction(BigInteger n, BigInteger d) {
            BigInteger g = gcd(n, d);
            this.num = n.divide(g);
            this.den = d.divide(g);
            if (this.den.compareTo(BigInteger.ZERO) < 0) {
                this.num = this.negate();
                this.den = this.den.negate();
            }
        }
        Fraction negate() {
            return new Fraction(num.negate(), den);
        }
        @Override
        public boolean equals(Object o) {
            if (!(o instanceof Fraction)) return false;
            Fraction f = (Fraction) o;
            return num.equals(f.num) && den.equals(f.den);
        }
    }
    private Fraction toFraction(String s) {
        if (!s.contains("(")) {
            if (!s.contains(".")) {
                return new Fraction(new BigInteger(s), BigInteger.ONE);
            } else {
                String[] parts = s.split("\\.");
                String intPart = parts[0];
                String fracPart = parts[1];
                BigInteger intBig = new BigInteger(intPart);
                if (fracPart.isEmpty()) {
                    return new Fraction(intBig, BigInteger.ONE);
                }
                BigInteger tenPow = BigInteger.TEN.pow(fracPart.length());
                BigInteger fracBig = new BigInteger(fracPart);
                BigInteger num = intBig.multiply(tenPow).add(fracBig);
                return new Fraction(num, tenPow);
            }
        } else {
            String[] parts = s.split("\\.");
            String intPart = parts[0];
            String rest = parts[1];
            int p = rest.indexOf('(');
            String nonRep = rest.substring(0, p);
            String rep = rest.substring(p+1, rest.length()-1);
            int a = nonRep.length();
            int b = rep.length();
            BigInteger I = new BigInteger(intPart);
            BigInteger N = nonRep.isEmpty() ? BigInteger.ZERO : new BigInteger(nonRep);
            BigInteger R = rep.isEmpty() ? BigInteger.ZERO : new BigInteger(rep);
            BigInteger pow10a = BigInteger.TEN.pow(a);
            BigInteger pow10b = BigInteger.TEN.pow(b);
            BigInteger denom = pow10a.multiply(pow10b.subtract(BigInteger.ONE));
            BigInteger num = I.multiply(denom)
                    .add(N.multiply(pow10b.subtract(BigInteger.ONE)))
                    .add(R);
            return new Fraction(num, denom);
        }
    }
}
