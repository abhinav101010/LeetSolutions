class Solution {
    public int maxRepeating(String sequence, String word) {
        int count = 0;
        String current = word;

        while (sequence.contains(current)) {
            count++;
            current += word;
        }

        return count;
    }
}