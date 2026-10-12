class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        string word;
        for (char c : sentence) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word.push_back(c);
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }

        for (int i = 0; i < (int)words.size(); i++) {
            if (words[i].find(searchWord) == 0) {
                return i + 1;
            }
        }

        return -1;
    }
};
