class Solution {
    public double minmaxGasDist(int[] stations, int k) {
        double lo = 0.0;
        double hi = stations[stations.length-1] - stations[0];
        for (int iter = 0; iter < 100; iter++) {
            double mid = (lo + hi) / 2.0;
            if (possible(stations, k, mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }
    
    private boolean possible(int[] stations, int k, double D) {
        int count = 0;
        for (int i = 1; i < stations.length; i++) {
            long gap = stations[i] - stations[i-1];
            // need ceil(gap / D) - 1 stations
            int needed = (int)Math.ceil(gap / D) - 1;
            count += needed;
            if (count > k) return false;
        }
        return count <= k;
    }
}
