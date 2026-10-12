class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count = 0;
        string current = word;

        while (sequence.find(current) != string::npos) {
            count++;
            current += word;
        }

        return count;
    }
};