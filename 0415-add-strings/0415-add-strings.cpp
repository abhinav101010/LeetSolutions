class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        string ans;
        while (i >= 0 || j >= 0 || carry) {
            int n1 = i >= 0 ? num1[i--] - '0' : 0;
            int n2 = j >= 0 ? num2[j--] - '0' : 0;
            int total = n1 + n2 + carry;
            ans = char(total % 10 + '0') + ans;
            carry = total / 10;
        }
        return ans;
    }
};