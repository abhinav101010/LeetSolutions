class Solution {
    public int[] plusOne(int[] digits) {
        // String s = "";
        // for(int d: digits){
        //     s = s+d;
        // }
        // String newNum = String.valueOf(Integer.valueOf(s)+1);
        // int[] ans = new int[newNum.length()];
        // for (int i = 0; i < newNum.length(); i++) {
        //     ans[i] = newNum.charAt(i) - '0';
        // }
        // return ans;

        // String s = "";
        // for (int d : digits) {
        //     s = s + d;
        // }

        // StringBuilder newNum = new StringBuilder(s);
        // int i = newNum.length() - 1;
        // while (i >= 0 && newNum.charAt(i) == '9') {
        //     newNum.setCharAt(i, '0');
        //     i--;
        // }

        // if (i >= 0) {
        //     newNum.setCharAt(i, (char)(newNum.charAt(i) + 1));
        // } else {
        //     newNum.insert(0, '1');
        // }

        // int[] ans = new int[newNum.length()];
        // for (i = 0; i < newNum.length(); i++) {
        //     ans[i] = newNum.charAt(i) - '0';
        // }

        // return ans;

        int i;
      
        for( i=digits.length-1; i>=0; i--)
        {
            
             if(digits[i]<9)
             {
                digits[i]++;
                return digits;
             }
             digits[i]=0;
             
        }
        int result[]=new int[digits.length+1];
        result[0]=1;
        return result;
    }
}