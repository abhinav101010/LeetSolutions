class Solution {
public:
    int lengthLongestPath(string input) {
        int maxLen = 0;
        unordered_map<int, int> pathLen;
        pathLen[0] = 0;
        
        stringstream ss(input);
        string line;
        while (getline(ss, line, '\n')) {
            int depth = 0;
            while (depth < (int)line.size() && line[depth] == '\t') depth++;
            string name = line.substr(depth);
            
            if (name.find('.') != string::npos) {
                maxLen = max(maxLen, pathLen[depth] + (int)name.size());
            } else {
                pathLen[depth + 1] = pathLen[depth] + name.size() + 1;
            }
        }
        
        return maxLen;
    }
};