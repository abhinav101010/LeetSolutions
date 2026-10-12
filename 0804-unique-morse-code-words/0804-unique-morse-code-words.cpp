class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> data = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> diffWays;
        for (const string& word : words) {
            string morseCode;
            for (char c : word) {
                morseCode += data[c - 'a'];
            }
            diffWays.insert(morseCode);
        }
        return diffWays.size();
    }
};