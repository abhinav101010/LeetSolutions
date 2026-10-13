class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int i = -1, j = -1, res = wordsDict.size();
        for (int k = 0; k < wordsDict.size(); k++) {
            if (wordsDict[k] == word1) i = k;
            if (wordsDict[k] == word2) j = k;
            if (i != -1 && j != -1) res = min(res, abs(i - j));
        }
        return res;
    }
};