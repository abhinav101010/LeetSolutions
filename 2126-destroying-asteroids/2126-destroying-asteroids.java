class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);
        long planetMass = mass;
        for (int asteroid : asteroids) {
            if (asteroid <= planetMass) {
                planetMass += asteroid;
            } else {
                return false;
            }
        }
        return true;
    }
}