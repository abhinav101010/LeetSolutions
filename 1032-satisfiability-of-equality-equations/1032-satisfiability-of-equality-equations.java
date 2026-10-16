class Solution {
    int[] parent = new int[26];
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void union(int x,int y) {
        parent[find(x)] = find(y);
    }
    public boolean equationsPossible(String[] equations) {
        for (int i=0;i<26;i++) parent[i]=i;
        for (String eq : equations) {
            if (eq.charAt(1)=='=') {
                int a = eq.charAt(0)-'a';
                int b = eq.charAt(3)-'a';
                union(a,b);
            }
        }
        for (String eq : equations) {
            if (eq.charAt(1)=='!') {
                int a = eq.charAt(0)-'a';
                int b = eq.charAt(3)-'a';
                if (find(a)==find(b)) return false;
            }
        }
        return true;
    }
}
