class Solution {
    public int sumOfTheDigitsOfHarshadNumber(int x) {
        // int sum = 0;
        // String str = String.valueOf(x);
        // for (int i = 0; i < str.length(); i++) {
        //     sum += Integer.valueOf(String.valueOf(str.charAt(i)));
        // }
        // if(x%sum == 0){
        //     return sum;
        // }
        // return -1;

        int sum = 0, temp = x;

        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        return x % sum == 0 ? sum : -1;
    }
}