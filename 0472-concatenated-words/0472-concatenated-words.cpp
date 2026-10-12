class Solution {
private:
    unordered_set<string> wordSet;
    unordered_map<string, bool> memo;
    
    bool canForm(const string& word) {
        if (memo.count(word)) return memo[word];
        for (int i = 1; i < (int)word.size(); i++) {
            string prefix = word.substr(0, i);
            string suffix = word.substr(i);
            if (wordSet.count(prefix) && (wordSet.count(suffix) || canForm(suffix))) {
                memo[word] = true;
                return true;
            }
        }
        memo[word] = false;
        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        wordSet = unordered_set<string>(words.begin(), words.end());
        vector<string> result;
        for (const string& word : words) {
            if (!word.empty() && canForm(word)) {
                result.push_back(word);
            }
        }
        return result;
    }
};