class Solution {
private:
    const vector<string> BELOW_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> TENS = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const vector<string> THOUSANDS = {"", "Thousand", "Million", "Billion"};
    
    string helper(int n) {
        if (n == 0) return "";
        if (n < 20) return BELOW_20[n] + " ";
        if (n < 100) return TENS[n / 10] + " " + helper(n % 10);
        return BELOW_20[n / 100] + " Hundred " + helper(n % 100);
    }
    
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        string result;
        for (int i = 0; num > 0; i++) {
            if (num % 1000 != 0) {
                result = helper(num % 1000) + THOUSANDS[i] + " " + result;
            }
            num /= 1000;
        }
        
        while (!result.empty() && result.back() == ' ') result.pop_back();
        return result;
    }
};