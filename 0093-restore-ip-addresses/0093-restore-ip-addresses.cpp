class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string sb;
        backtrack(s, 0, 0, sb, ans);
        return ans;
    }

private:
    void backtrack(const string& s, int index, int dots, string& sb, vector<string>& ans) {
        if (dots == 3) {
            if (index < s.size()) {
                string last = s.substr(index);
                if (valid(last)) {
                    sb += last;
                    ans.push_back(sb);
                    sb.erase(sb.size() - last.size());
                }
            }
            return;
        }

        int len = sb.size();
        for (int take = 1; take <= 3 && index + take < s.size(); take++) {
            string part = s.substr(index, take);
            if (!valid(part)) {
                break;
            }
            sb += part;
            sb += '.';
            backtrack(s, index + take, dots + 1, sb, ans);
            sb.resize(len);
        }
    }

    bool valid(const string& part) {
        if (part.size() > 3) {
            return false;
        }
        if (part.size() > 1 && part[0] == '0') {
            return false;
        }
        return stoi(part) <= 255;
    }
};
