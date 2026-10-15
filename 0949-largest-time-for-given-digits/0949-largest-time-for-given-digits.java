import java.util.Arrays;
class Solution {
    private boolean nextPermutation(int[] arr) {
        int i = arr.length - 2;
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }
        if (i < 0) {
            return false;
        }
        int j = arr.length - 1;
        while (arr[j] <= arr[i]) {
            j--;
        }
        swap(arr, i, j);
        reverse(arr, i + 1, arr.length - 1);
        return true;
    }
    private void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    private void reverse(int[] arr, int start, int end) {
        while (start < end) {
            swap(arr, start, end);
            start++;
            end--;
        }
    }
    public String largestTimeFromDigits(int[] A) {
        int[] arr = Arrays.copyOf(A, A.length);
        Arrays.sort(arr);
        String best = "";
        do {
            int hour = arr[0]*10 + arr[1];
            int minute = arr[2]*10 + arr[3];
            if (hour < 24 && minute < 60) {
                String t = String.format("%02d:%02d", hour, minute);
                if (t.compareTo(best) > 0) {
                    best = t;
                }
            }
        } while (nextPermutation(arr));
        return best;
    }
}
