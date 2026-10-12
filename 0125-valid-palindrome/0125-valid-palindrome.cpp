class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); }), s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int left = 0;
        int right = s.length()-1;

        bool palindrome = true;
        while(left<right){
            if(s[left] != s[right]) palindrome = false;
            left++;
            right--;
        }

        return palindrome;
    }
};