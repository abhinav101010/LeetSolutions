class Solution {
    private int check(int[] A,int[] B,int x,int n) {
        int ra=0, rb=0;
        for (int i=0;i<n;i++) {
            if (A[i]!=x && B[i]!=x) return 1000000000;
            else if (A[i]!=x) ra++;
            else if (B[i]!=x) rb++;
        }
        return Math.min(ra,rb);
    }
    public int minDominoRotations(int[] A,int[] B) {
        int n=A.length;
        int res = Math.min(check(A,B,A[0],n), check(A,B,B[0],n));
        return res>=1000000000?-1:res;
    }
}
