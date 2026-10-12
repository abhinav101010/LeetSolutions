class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int read = 0;
        int n = chars.size();
        
        while (read < n) {
            char c = chars[read];
            int count = 0;
            while (read < n && chars[read] == c) {
                read++;
                count++;
            }
            
            chars[write++] = c;
            
            if (count > 1) {
                string countStr = to_string(count);
                for (char d : countStr) {
                    chars[write++] = d;
                }
            }
        }
        
        return write;
    }
};