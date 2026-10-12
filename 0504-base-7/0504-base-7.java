class Solution {
    public String convertToBase7(int num) {
        if (num == 0) return "0";
        
        String sign = "";
        if (num < 0) {
            sign = "-";
            num = -num;
        }
        
        StringBuilder ans = new StringBuilder();
        while (num > 0) {
            int remainder = num % 7;
            ans.insert(0, remainder);
            num /= 7;
        }
        
        return sign + ans.toString();
    }
}