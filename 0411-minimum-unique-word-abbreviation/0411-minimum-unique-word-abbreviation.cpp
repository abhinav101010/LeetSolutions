class Solution {
public:
    string res;
    int n;
    vector<string> dictList;
    
    bool isMatch(const string &abbr, const string &word) {
        int i = 0, j = 0;
        while (i < abbr.size() && j < word.size()) {
            if (isdigit(abbr[i])) {
                if (abbr[i] == '0') return false;
                int k = i;
                while (k < abbr.size() && isdigit(abbr[k])) k++;
                int num = stoi(abbr.substr(i, k - i));
                j += num;
                i = k;
            } else if (abbr[i] == word[j]) {
                i++; j++;
            } else {
                return false;
            }
        }
        return i == abbr.size() && j == word.size();
    }
    
    void backtrack(const string &target, int pos, int count, string cur) {
        if (pos == n) {
            if (count > 0) cur += to_string(count);
            string cand = cur;
            bool match = false;
            for (auto &d : dictList) {
                if (isMatch(cand, d)) {
                    match = true;
                    break;
                }
            }
            if (!match) {
                if (cand.size() < res.size() || (cand.size() == res.size() && cand < res)) {
                    res = cand;
                }
            }
            return;
        }
        if (count > 0) {
            backtrack(target, pos + 1, count + 1, cur);
            string newCur = cur + to_string(count) + target[pos];
            backtrack(target, pos + 1, 0, newCur);
        } else {
            backtrack(target, pos + 1, 1, cur);
            string newCur = cur + target[pos];
            backtrack(target, pos + 1, 0, newCur);
        }
    }
    
    string minAbbreviation(string target, vector<string>& dictionary) {
        n = target.size();
        res = target;
        for (auto &d : dictionary) {
            if (d.size() == n) dictList.push_back(d);
        }
        backtrack(target, 0, 0, "");
        return res;
    }
};