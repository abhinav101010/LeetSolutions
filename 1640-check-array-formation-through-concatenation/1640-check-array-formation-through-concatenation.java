import java.util.Arrays;

class Solution {
    public boolean canFormArray(int[] arr, int[][] pieces) {
        int i = 0;

        while (i < arr.length) {
            boolean found = false;

            for (int[] piece : pieces) {
                if (piece[0] == arr[i]) {
                    if (!Arrays.equals(Arrays.copyOfRange(arr, i, i + piece.length), piece)) {
                        return false;
                    }

                    i += piece.length;
                    found = true;
                    break;
                }
            }

            if (!found) {
                return false;
            }
        }

        return true;
    }
}