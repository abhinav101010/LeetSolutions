class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        dfs(s, 0, path, ans);
        return ans;
    }

private:
    void dfs(const string& s, int start, vector<string>& path, vector<vector<string>>& ans) {
        if (start == (int)s.size()) {
            ans.push_back(path);
            return;
        }
        for (int end = start; end < (int)s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1, path, ans);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};