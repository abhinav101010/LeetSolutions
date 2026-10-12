class Solution {
    public String toGoatLatin(String sentence) {
        String vowels = "aeiouAEIOU";
        String[] words = sentence.split(" ");
        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < words.length; i++) {
            String word = words[i];

            if (vowels.indexOf(word.charAt(0)) < 0) {
                word = word.substring(1) + word.charAt(0);
            }

            word += "ma";
            word += "a".repeat(i + 1);

            if (i > 0) ans.append(" ");
            ans.append(word);
        }

        return ans.toString();
    }
}