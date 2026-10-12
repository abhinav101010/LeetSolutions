class Solution {
    public int rand10() {
        while (true) {
            int row = rand7();
            int col = rand7();
            int idx = (row - 1) * 7 + col;
            if (idx <= 40) {
                return 1 + (idx - 1) % 10;
            }
        }
    }
    
    private int rand7() {
        return (int)(Math.random() * 7) + 1;
    }
}