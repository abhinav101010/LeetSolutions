class Solution {
public:
    string nearestPalindromic(string n) {
        if (n == "1") return "0";
        
        int length = n.size();
        unordered_set<string> candidates;
        
        candidates.insert(to_string((long long)pow(10, length) + 1));
        candidates.insert(to_string((long long)pow(10, length - 1) - 1));
        
        int prefix = stoi(n.substr(0, (length + 1) / 2));
        for (int i : {prefix - 1, prefix, prefix + 1}) {
            string s = to_string(i);
            string pal;
            if (length % 2 == 0) {
                pal = s + string(s.rbegin(), s.rend());
            } else {
                pal = s + string(s.rbegin() + 1, s.rend());
            }
            candidates.insert(pal);
        }
        
        candidates.erase(n);
        
        long long target = stoll(n);
        long long minDiff = LLONG_MAX;
        string result;
        
        for (const string& cand : candidates) {
            long long diff = abs(stoll(cand) - target);
            if (diff < minDiff || (diff == minDiff && stoll(cand) < stoll(result))) {
                minDiff = diff;
                result = cand;
            }
        }
        
        return result;
    }
};