class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) return false;
        int[] mapStoT = new int[256];
        int[] mapTtoS = new int[256];
        Arrays.fill(mapStoT, -1);
        Arrays.fill(mapTtoS, -1);
        for (int i = 0; i < s.length(); ++i) {
            char sc = s.charAt(i);
            char tc = t.charAt(i);
            if (mapStoT[sc] == -1 && mapTtoS[tc] == -1) {
                mapStoT[sc] = tc;
                mapTtoS[tc] = sc;
            } else if (mapStoT[sc] != tc || mapTtoS[tc] != sc) {
                return false;
            }
        }
        return true;
    }
}