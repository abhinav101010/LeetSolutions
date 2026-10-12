class Solution {
    public int[] fairCandySwap(int[] aliceSizes, int[] bobSizes) {
        int aliceSum = 0, bobSum = 0;
        for (int a : aliceSizes) aliceSum += a;
        for (int b : bobSizes) bobSum += b;
        
        int diff = (bobSum - aliceSum) / 2;
        
        Set<Integer> bobSet = new HashSet<>();
        for (int b : bobSizes) bobSet.add(b);
        
        for (int a : aliceSizes) {
            int b = a + diff;
            if (bobSet.contains(b)) {
                return new int[]{a, b};
            }
        }
        return new int[0];
    }
}