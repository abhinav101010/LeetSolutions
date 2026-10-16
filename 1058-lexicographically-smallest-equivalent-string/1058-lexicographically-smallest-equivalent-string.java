class Solution {
    int[] parent = new int[26];
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void union(int x,int y) {
        int p1 = find(x), p2 = find(y);
        if (p1 < p2) parent[p2] = p1;
        else parent[p1] = p2;
    }
    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        for (int i=0;i<26;i++) parent[i]=i;
        for (int i=0;i<s1.length();i++) {
            union(s1.charAt(i)-'a', s2.charAt(i)-'a');
        }
        StringBuilder sb = new StringBuilder();
        for (char c : baseStr.toCharArray()) {
            int p = find(c-'a');
            sb.append((char)('a'+p));
        }
        return sb.toString();
    }
}
