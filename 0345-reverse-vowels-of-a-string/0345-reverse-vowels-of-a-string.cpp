class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (left < right && vowels.count(s[left]) == 0) {
                left++;
            }
            while (left < right && vowels.count(s[right]) == 0) {
                right--;
            }
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
        return s;
    }
};