class Solution {
    public int maximumPopulation(int[][] logs) {
        int maxPopulation = 0;
        int answer = 1950;
        for (int year = 1950; year < 2050; year++) {
            int population = 0;
            for (int[] log : logs) {
                if (log[0] <= year && year < log[1]) {
                    population++;
                }
            }
            if (population > maxPopulation) {
                maxPopulation = population;
                answer = year;
            }
        }
        return answer;
    }
}