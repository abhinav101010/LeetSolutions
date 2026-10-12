class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlt = 0;
        int alt = 0;

        for (int i = 0; i < gain.size(); i++) {
            alt += gain[i];
            maxAlt = max(maxAlt, alt);
        }

        return maxAlt;
    }
};