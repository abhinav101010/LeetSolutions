class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int pixels = 0;

        for (char c : s) {
            int width = widths[c - 'a'];

            if (pixels + width > 100) {
                lines++;
                pixels = width;
            } else {
                pixels += width;
            }
        }

        return {lines, pixels};
    }
};