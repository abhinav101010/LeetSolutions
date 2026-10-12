class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if (a == b) return 1;
        string s = a;
        int count = 1;
        while (s.size() < b.size()) {
            s += a;
            count++;
        }
        if (s.find(b) != string::npos) return count;
        s += a;
        count++;
        if (s.find(b) != string::npos) return count;
        return -1;
    }
};