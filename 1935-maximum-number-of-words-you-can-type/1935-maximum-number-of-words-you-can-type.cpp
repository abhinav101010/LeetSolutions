class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for (char ch : brokenLetters) {
            broken[ch - 'a'] = true;
        }
        int count = 0;
        string word;
        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                bool canType = true;
                for (char ch : word) {
                    if (broken[ch - 'a']) {
                        canType = false;
                        break;
                    }
                }
                if (canType) {
                    count++;
                }
                word.clear();
            } else {
                word += text[i];
            }
        }
        return count;
    }
};