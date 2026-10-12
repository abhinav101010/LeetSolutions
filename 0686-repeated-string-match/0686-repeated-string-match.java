class Solution {
    public int repeatedStringMatch(String a, String b) {
        if (a.equals(b)) return 1;
        StringBuilder s = new StringBuilder(a);
        int count = 1;
        while (s.length() < b.length()) {
            s.append(a);
            count++;
        }
        if (s.toString().contains(b)) return count;
        s.append(a);
        count++;
        if (s.toString().contains(b)) return count;
        return -1;
    }
}