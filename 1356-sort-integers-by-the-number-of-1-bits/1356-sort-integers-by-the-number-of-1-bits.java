class Solution {
    public int[] sortByBits(int[] arr) {
        Integer[] boxed = new Integer[arr.length];
        for (int i = 0; i < arr.length; i++) {
            boxed[i] = arr[i];
        }
        Arrays.sort(boxed, (a, b) -> {
            int bitA = Integer.bitCount(a);
            int bitB = Integer.bitCount(b);
            if (bitA != bitB) return bitA - bitB;
            return a - b;
        });
        for (int i = 0; i < arr.length; i++) {
            arr[i] = boxed[i];
        }
        return arr;
    }
}