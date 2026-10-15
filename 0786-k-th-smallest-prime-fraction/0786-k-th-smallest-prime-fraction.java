class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        int n = arr.length;
        double left = 0.0, right = 1.0;
        int bestNum = 0, bestDen = 1;
        while (right - left > 1e-9) {
            double mid = (left + right) / 2.0;
            int count = 0;
            int j = n - 1;
            int curNum = 0, curDen = 1;
            for (int i = 0; i < n; i++) {
                while (j >= 0 && arr[i] > mid * arr[j]) {
                    j--;
                }
                if (j < 0) break;
                count += j + 1;
                if (j >= 0) {
                    if (arr[i] * curDen > curNum * arr[j]) {
                        curNum = arr[i];
                        curDen = arr[j];
                    }
                }
            }
            if (count < k) {
                left = mid;
            } else {
                right = mid;
                bestNum = curNum;
                bestDen = curDen;
            }
        }
        return new int[]{bestNum, bestDen};
    }
}
