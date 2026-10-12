class Solution {
public:
    int nextGreaterElement(int n) {
        string digits = to_string(n);
        int i = digits.size() - 2;
        while (i >= 0 && digits[i] >= digits[i + 1]) i--;
        if (i == -1) return -1;
        
        int j = digits.size() - 1;
        while (digits[j] <= digits[i]) j--;
        
        swap(digits[i], digits[j]);
        reverse(digits.begin() + i + 1, digits.end());
        
        long long result = stoll(digits);
        return result > INT_MAX ? -1 : (int)result;
    }
};