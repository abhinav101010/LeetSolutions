class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return getValue(firstWord) + getValue(secondWord) == getValue(targetWord);
    }
    
private:
    int getValue(const string& word) {
        int num = 0;
        for (char ch : word) {
            num = num * 10 + (ch - 'a');
        }
        return num;
    }
};