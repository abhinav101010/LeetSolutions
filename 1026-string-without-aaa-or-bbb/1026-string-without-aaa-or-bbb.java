class Solution {
    public String strWithout3a3b(int a, int b) {
        StringBuilder res = new StringBuilder();
        int i = 0, j = 0; // a,b count used
        int ca = 0, cb = 0; // consecutive
        while (i < a || j < b) {
            if (res.length() >= 2 && res.charAt(res.length()-1)=='a' && res.charAt(res.length()-2)=='a') {
                res.append('b'); j++; cb = ca==0?1:cb+1; ca = 0;
            } else if (res.length() >= 2 && res.charAt(res.length()-1)=='b' && res.charAt(res.length()-2)=='b') {
                res.append('a'); i++; ca = cb==0?1:ca+1; cb = 0;
            } else if (i < a && (j >= b || i > j)) {
                res.append('a'); i++; ca++; cb = 0;
            } else {
                res.append('b'); j++; cb++; ca = 0;
            }
        }
        return res.toString();
    }
}
