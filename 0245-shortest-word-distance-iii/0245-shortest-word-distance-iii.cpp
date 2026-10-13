class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int res = wordsDict.size();
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) {
                for (int j = 0; j < wordsDict.size(); j++) {
                    if (i != j && wordsDict[j] == word2) {
                        res = min(res, abs(i - j));
                    }
                }
            }
        }
        return res;
    }
};