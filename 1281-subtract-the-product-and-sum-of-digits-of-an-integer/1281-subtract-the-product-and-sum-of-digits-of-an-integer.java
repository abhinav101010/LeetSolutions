class Solution {
    public int subtractProductAndSum(int n) {
        int product = 1, add = 0;
        while(n > 0){
            add += n%10;
            product *= n%10;
            n /= 10;
        }

        return product-add;
    }
}