class Solution {
    public boolean isStrobogrammatic(String num) {
        int left = 0, right = num.length() - 1;
        while (left <= right) {
            char c1 = num.charAt(left), c2 = num.charAt(right);
            if ((c1 == '0' && c2 == '0') || (c1 == '1' && c2 == '1') || (c1 == '6' && c2 == '9') || (c1 == '8' && c2 == '8') || (c1 == '9' && c2 == '6')) {
                left++; right--;
            } else {
                return false;
            }
        }
        return true;
    }
}