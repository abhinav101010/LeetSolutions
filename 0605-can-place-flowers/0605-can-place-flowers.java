class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int length = flowerbed.length;
        for (int i = 0; i < length; i++) {
            if (i > 0 && i < length - 1) {
                if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            } else if (i == 0) {
                if (length == 1) {
                    if (flowerbed[0] == 0) {
                        n--;
                    }
                } else {
                    if (flowerbed[0] == 0 && flowerbed[1] == 0) {
                        flowerbed[0] = 1;
                        n--;
                    }
                }
            } else if (i == length - 1) {
                if (flowerbed[length - 1] == 0 && flowerbed[length - 2] == 0) {
                    flowerbed[length - 1] = 1;
                    n--;
                }
            }
            if (n <= 0) {
                return true;
            }
        }
        return n <= 0;
    }
}
