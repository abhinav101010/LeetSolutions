class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> contentToFiles;
        
        for (const string& path : paths) {
            stringstream ss(path);
            string directory;
            ss >> directory;
            string fileInfo;
            while (ss >> fileInfo) {
                int idx = fileInfo.find('(');
                string filename = fileInfo.substr(0, idx);
                string content = fileInfo.substr(idx + 1, fileInfo.size() - idx - 2);
                contentToFiles[content].push_back(directory + "/" + filename);
            }
        }
        
        vector<vector<string>> result;
        for (auto& [_, files] : contentToFiles) {
            if (files.size() > 1) result.push_back(files);
        }
        return result;
    }
};