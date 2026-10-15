import java.util.*;

class Master {
    public int guess(String word) {
        // dummy implementation; actual logic provided by LeetCode
        return 0;
    }
}

class Solution {
    public void findSecretWord(String[] wordlist, Master master) {
        List<String> candidates = new ArrayList<>(Arrays.asList(wordlist));
        Random rand = new Random();
        for (int i = 0; i < 10; i++) {
            if (candidates.isEmpty()) break;
            int idx = rand.nextInt(candidates.size());
            String guessWord = candidates.get(idx);
            int matches = master.guess(guessWord);
            List<String> newCandidates = new ArrayList<>();
            for (String w : candidates) {
                if (matchCount(guessWord, w) == matches) {
                    newCandidates.add(w);
                }
            }
            candidates = newCandidates;
        }
    }
    private int matchCount(String a, String b) {
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) == b.charAt(i)) {
                count++;
            }
        }
        return count;
    }
}
