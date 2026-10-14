import java.util.*;

class Solution {
    public String findContestMatch(int n) {
        List<String> teams = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            teams.add(String.valueOf(i));
        }
        while (teams.size() > 1) {
            int half = teams.size() / 2;
            List<String> newTeams = new ArrayList<>();
            for (int i = 0; i < half; i++) {
                newTeams.add("(" + teams.get(i) + "," + teams.get(teams.size() - 1 - i) + ")");
            }
            teams = newTeams;
        }
        return teams.get(0);
    }
}
