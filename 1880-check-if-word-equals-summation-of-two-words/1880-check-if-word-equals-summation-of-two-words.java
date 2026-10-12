class Solution {
    public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
        return getValue(firstWord) + getValue(secondWord) == getValue(targetWord);
    }
    
    private int getValue(String word) {
        int num = 0;
        for (char ch : word.toCharArray()) {
            num = num * 10 + (ch - 'a');
        }
        return num;
    }
}