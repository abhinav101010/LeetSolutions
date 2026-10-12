class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return {};
        
        unordered_map<string, vector<string>> graph;
        for (const string& word : wordSet) {
            for (int i = 0; i < (int)word.size(); i++) {
                string pattern = word.substr(0, i) + '*' + word.substr(i + 1);
                graph[pattern].push_back(word);
            }
        }
        
        unordered_map<string, vector<vector<string>>> level;
        level[beginWord] = {{beginWord}};
        unordered_set<string> visited = {beginWord};
        bool found = false;
        
        while (!level.empty() && !found) {
            unordered_map<string, vector<vector<string>>> nextLevel;
            for (auto& [word, paths] : level) {
                if (word == endWord) {
                    found = true;
                    return paths;
                }
                
                for (int i = 0; i < (int)word.size(); i++) {
                    string pattern = word.substr(0, i) + '*' + word.substr(i + 1);
                    if (graph.count(pattern)) {
                        for (const string& nei : graph[pattern]) {
                            if (!visited.count(nei)) {
                                for (auto& path : paths) {
                                    vector<string> newPath = path;
                                    newPath.push_back(nei);
                                    nextLevel[nei].push_back(newPath);
                                }
                            }
                        }
                    }
                }
            }
            
            for (auto& [k, v] : nextLevel) visited.insert(k);
            level = move(nextLevel);
        }
        
        return {};
    }
};