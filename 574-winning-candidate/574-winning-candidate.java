import java.util.*;

class Candidate { int id; String name; int vote; }

class Solution {
    public String winningCandidate(List<Candidate> candidates) {
        if (candidates.isEmpty()) return "";
        int maxVote = candidates.get(0).vote;
        for (Candidate c : candidates) maxVote = Math.max(maxVote, c.vote);
        for (Candidate c : candidates) if (c.vote == maxVote) return c.name;
        return "";
    }
}
