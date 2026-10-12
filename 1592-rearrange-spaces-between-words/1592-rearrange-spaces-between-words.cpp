class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        int spaces = 0;

        for (char c : text) {
            if (c == ' ') {
                spaces++;
            }
        }

        stringstream ss(text);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        if (words.size() == 1) {
            return words[0] + string(spaces, ' ');
        }

        int gap = spaces / (words.size() - 1);
        int extra = spaces % (words.size() - 1);

        string res;
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) {
                res += string(gap, ' ');
            }
            res += words[i];
        }
        res += string(extra, ' ');

        return res;
    }
};
