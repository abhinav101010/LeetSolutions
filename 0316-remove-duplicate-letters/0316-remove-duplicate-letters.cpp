class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastOccurrence(26, -1);
        for (int i = 0; i < (int)s.size(); i++) {
            lastOccurrence[s[i] - 'a'] = i;
        }
        
        vector<char> stack;
        vector<bool> inStack(26, false);
        
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (inStack[c - 'a']) continue;
            
            while (!stack.empty() && c < stack.back() && i < lastOccurrence[stack.back() - 'a']) {
                inStack[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            stack.push_back(c);
            inStack[c - 'a'] = true;
        }
        
        return string(stack.begin(), stack.end());
    }
};