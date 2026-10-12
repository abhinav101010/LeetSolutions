/*
Valid Phone Numbers - Shell solution:
grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt
*/

class Solution {
public:
    string validPhoneNumbers() {
        return "grep -P '^(\\d{3}-|\\(\\d{3}\\) )\\d{3}-\\d{4}$' file.txt";
    }
};