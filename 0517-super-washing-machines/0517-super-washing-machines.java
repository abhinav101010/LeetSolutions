class Solution {
    public int findMinMoves(int[] machines) {
        int total = 0;
        for (int m : machines) total += m;
        int n = machines.length;
        if (total % n != 0) return -1;
        int avg = total / n;
        
        int maxMoves = 0;
        int balance = 0;
        for (int m : machines) {
            balance += m - avg;
            maxMoves = Math.max(maxMoves, Math.max(Math.abs(balance), m - avg));
        }
        
        return maxMoves;
    }
}