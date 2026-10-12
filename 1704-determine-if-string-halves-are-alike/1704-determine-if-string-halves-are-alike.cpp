class Solution {
public:
    bool halvesAreAlike(string s) {
        int mid = s.size() / 2;
        int first = 0, second = 0;

        for (int i = 0; i < mid; i++) {
            if (isVowel(s[i])) first++;
            if (isVowel(s[i + mid])) second++;
        }

        return first == second;
    }

private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};