import java.math.BigInteger;
class Solution {
    public boolean isRationalEqual(String s, String t) {
        return value(s).equals(value(t));
    }
    private BigInteger[] value(String s) {
        // return [num, den] representing value
        int dot = s.indexOf('.');
        if (dot == -1) {
            return new BigInteger[]{new BigInteger(s), BigInteger.ONE};
        }
        String intp = s.substring(0, dot);
        String frac = s.substring(dot+1);
        int lp = frac.indexOf('(');
        if (lp == -1) {
            BigInteger num = new BigInteger(intp + frac);
            BigInteger den = BigInteger.TEN.pow(frac.length());
            return reduce(num, den);
        }
        String nonrep = frac.substring(0, lp);
        String rep = frac.substring(lp+1, frac.length()-1);
        BigInteger numFull = new BigInteger(intp + nonrep + rep);
        BigInteger denFull = BigInteger.TEN.pow(nonrep.length() + rep.length()).subtract(BigInteger.TEN.pow(nonrep.length()));
        return reduce(numFull, denFull);
    }
    private BigInteger[] reduce(BigInteger a, BigInteger b) {
        BigInteger g = a.gcd(b);
        return new BigInteger[]{a.divide(g), b.divide(g)};
    }
}
