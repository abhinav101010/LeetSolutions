class Solution {
    public int countDigits(int num) {
        int temp = num;
        int ans = 0;
        while(temp > 0){
            int n = temp%10;

            if(num%n == 0){
                ans++;
            }
            temp /= 10;
        }
        return ans;
    }
}