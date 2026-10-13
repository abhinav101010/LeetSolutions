class WordDistance {
public:
    unordered_map<string, vector<int>> pos;
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); i++) {
            pos[wordsDict[i]].push_back(i);
        }
    }
    int shortest(string word1, string word2) {
        auto &p1 = pos[word1], &p2 = pos[word2];
        int i = 0, j = 0, res = INT_MAX;
        while (i < p1.size() && j < p2.size()) {
            res = min(res, abs(p1[i] - p2[j]));
            if (p1[i] < p2[j]) i++; else j++;
        }
        return res;
    }
};