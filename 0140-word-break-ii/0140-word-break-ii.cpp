class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return dfs(s, 0, wordSet, memo);
    }
    
private:
    vector<string> dfs(const string& s, int start, const unordered_set<string>& wordSet, unordered_map<int, vector<string>>& memo) {
        if (memo.count(start)) return memo[start];
        
        vector<string> result;
        if (start == (int)s.size()) {
            result.push_back("");
            return result;
        }
        
        for (int end = start + 1; end <= (int)s.size(); end++) {
            string word = s.substr(start, end - start);
            if (wordSet.count(word)) {
                for (const string& suffix : dfs(s, end, wordSet, memo)) {
                    if (suffix.empty()) {
                        result.push_back(word);
                    } else {
                        result.push_back(word + " " + suffix);
                    }
                }
            }
        }
        
        memo[start] = result;
        return result;
    }
};