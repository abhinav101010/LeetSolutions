class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] data = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        java.util.Set<String> diffWays = new java.util.HashSet<>();
        for (String word : words) {
            StringBuilder morseCode = new StringBuilder();
            for (char c : word.toCharArray()) {
                morseCode.append(data[c - 'a']);
            }
            diffWays.add(morseCode.toString());
        }
        return diffWays.size();
    }
}