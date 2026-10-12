/*
Valid Phone Numbers - Shell solution:
grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt
*/

import java.util.*;

class Solution {
    public String validPhoneNumbers() {
        return "grep -P '^(\\\\d{3}-|\\\\(\\\\d{3}\\\\) )\\\\d{3}-\\\\d{4}$' file.txt";
    }
}