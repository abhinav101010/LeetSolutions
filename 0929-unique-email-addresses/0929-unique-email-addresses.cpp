class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;
        for (string& email : emails) {
            string local, domain;
            bool plus = false;
            bool at = false;
            for (char c : email) {
                if (c == '@') {
                    at = true;
                    continue;
                }
                if (!at) {
                    if (c == '+') {
                        plus = true;
                        continue;
                    }
                    if (plus) {
                        continue;
                    }
                    if (c == '.') {
                        continue;
                    }
                    local += c;
                } else {
                    domain += c;
                }
            }
            unique.insert(local + "@" + domain);
        }
        return (int)unique.size();
    }
};