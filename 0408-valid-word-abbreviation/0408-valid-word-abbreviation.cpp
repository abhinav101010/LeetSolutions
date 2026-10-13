class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < (int)word.size() && j < (int)abbr.size()) {
            if (word[i] == abbr[j]) {
                i++; j++;
                continue;
            }
            if (!isdigit(abbr[j]) || abbr[j] == '0') return false;
            int k = j;
            while (k < (int)abbr.size() && isdigit(abbr[k])) k++;
            int num = stoi(abbr.substr(j, k - j));
            i += num;
            j = k;
        }
        return i == (int)word.size() && j == (int)abbr.size();
    }
};