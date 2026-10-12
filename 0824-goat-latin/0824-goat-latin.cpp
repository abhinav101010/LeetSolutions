class Solution {
public:
    string toGoatLatin(string sentence) {
        string vowels = "aeiouAEIOU";
        vector<string> words;
        string word;
        for (char c : sentence) {
            if (c == ' ') {
                words.push_back(word);
                word.clear();
            } else {
                word += c;
            }
        }
        if (!word.empty()) words.push_back(word);
        
        string ans;
        for (int i = 0; i < (int)words.size(); i++) {
            string w = words[i];
            if (vowels.find(w[0]) == string::npos) {
                w = w.substr(1) + w[0];
            }
            w += "ma";
            w += string(i + 1, 'a');
            
            if (i > 0) ans += " ";
            ans += w;
        }
        return ans;
    }
};