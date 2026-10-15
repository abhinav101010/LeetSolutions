class Solution {
    public int[] diStringMatch(String s) {
        int lo = 0, hi = s.length();
        int[] res = new int[s.length()+1];
        int idx = 0;
        for (char ch : s.toCharArray()) {
            if (ch == 'I') {
                res[idx++] = lo++;
            } else {
                res[idx++] = hi--;
            }
        }
        res[idx] = lo; // lo == hi
        return res;
    }
}
