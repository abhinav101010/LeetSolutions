class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        const char* hex = "0123456789abcdef";
        string ans;
        while (num != 0) {
            ans = hex[num & 15] + ans;
            num = (unsigned int)num >> 4;
        }
        return ans;
    }
};