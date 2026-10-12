class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long planetMass = mass;
        for (int asteroid : asteroids) {
            if (asteroid <= planetMass) {
                planetMass += asteroid;
            } else {
                return false;
            }
        }
        return true;
    }
};