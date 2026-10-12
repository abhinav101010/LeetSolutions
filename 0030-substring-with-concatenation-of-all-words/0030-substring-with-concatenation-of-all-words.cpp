class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int wordLen = words[0].size();
        int totalLen = wordLen * words.size();
        int n = s.size();
        
        if (n < totalLen) return result;
        
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }
        
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> currentCount;
            
            for (int j = i; j <= n - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);
                
                if (wordCount.count(word)) {
                    currentCount[word]++;
                    count++;
                    
                    while (currentCount[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currentCount[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    
                    if (count == (int)words.size()) {
                        result.push_back(left);
                    }
                } else {
                    currentCount.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        
        return result;
    }
};