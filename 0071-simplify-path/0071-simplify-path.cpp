class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string cur;

        for (int i = 0; i <= (int)path.size(); i++) {
            if (i == (int)path.size() || path[i] == '/') {
                if (cur.empty()) {
                    continue;
                }
                if (cur == "..") {
                    if (!st.empty()) {
                        st.pop_back();
                    }
                } else if (cur != ".") {
                    st.push_back(cur);
                }
                cur.clear();
            } else {
                cur.push_back(path[i]);
            }
        }

        string ans;
        for (string& s : st) {
            ans += "/" + s;
        }

        return ans.empty() ? "/" : ans;
    }
};
