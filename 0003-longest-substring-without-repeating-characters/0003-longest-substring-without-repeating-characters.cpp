class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int maxSize = 0;
        int j = 0;
        int start=0;
        for(int start = 0; start < s.length(); start++) {
    set<char> st;

    for(int i = start; i < s.length(); i++) {
        if(st.count(s[i]))
            break;

        st.insert(s[i]);
    }

    maxSize = max(maxSize, (int)st.size());
}
       maxSize = max(maxSize, (int)st.size());
        return maxSize;
    }
};