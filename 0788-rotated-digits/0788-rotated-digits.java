class Solution {
    public int rotatedDigits(int n) {
        int ans = 0;
        for (int num = 1; num <= n; num++) {
            int rotatedNum = 0;
            int place = 1;
            int temp = num;
            boolean valid = true;
            boolean changed = false;
            
            while (temp > 0) {
                int digit = temp % 10;
                int rotated = 0;
                switch (digit) {
                    case 0: case 1: case 8:
                        rotated = digit;
                        break;
                    case 2:
                        rotated = 5;
                        changed = true;
                        break;
                    case 5:
                        rotated = 2;
                        changed = true;
                        break;
                    case 6:
                        rotated = 9;
                        changed = true;
                        break;
                    case 9:
                        rotated = 6;
                        changed = true;
                        break;
                    default:
                        valid = false;
                        break;
                }
                if (!valid) break;
                rotatedNum += rotated * place;
                place *= 10;
                temp /= 10;
            }
            if (valid && changed) ans++;
        }
        return ans;
    }
}