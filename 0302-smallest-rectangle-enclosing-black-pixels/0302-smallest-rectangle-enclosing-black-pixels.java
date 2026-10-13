import java.util.*;

class Solution {
    public int minArea(char[][] image, int x, int y) {
        int left = searchLeft(image, 0, y, true);
        int right = searchRight(image, y, image[0].length - 1, true);
        int top = searchLeft(image, 0, x, false);
        int bottom = searchRight(image, x, image.length - 1, false);
        return (right - left + 1) * (bottom - top + 1);
    }
    
    private int searchLeft(char[][] image, int low, int high, boolean isCol) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (hasBlack(image, mid, isCol)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    
    private int searchRight(char[][] image, int low, int high, boolean isCol) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (hasBlack(image, mid, isCol)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
    
    private boolean hasBlack(char[][] image, int mid, boolean isCol) {
        if (isCol) {
            for (int i = 0; i < image.length; i++) {
                if (image[i][mid] == '1') return true;
            }
        } else {
            for (int j = 0; j < image[0].length; j++) {
                if (image[mid][j] == '1') return true;
            }
        }
        return false;
    }
}