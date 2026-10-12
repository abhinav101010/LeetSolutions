class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited = {beginWord};
        int level = 1;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                
                if (word == endWord) return level;
                
                for (int j = 0; j < (int)word.size(); j++) {
                    char original = word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;
                        if (wordSet.count(word) && !visited.count(word)) {
                            visited.insert(word);
                            q.push(word);
                        }
                    }
                    word[j] = original;
                }
            }
            level++;
        }
        
        return 0;
    }
};