class Solution {
public:
    int findNthDigit(int n) {
        long long length = 1, count = 9, start = 1;
        long long nLong = n;
        
        while (nLong > length * count) {
            nLong -= length * count;
            length++;
            count *= 10;
            start *= 10;
        }
        
        start += (nLong - 1) / length;
        string s = to_string(start);
        return s[(nLong - 1) % length] - '0';
    }
};