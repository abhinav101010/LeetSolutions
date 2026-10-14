class StringIterator {
    private String s;
    private int i;
    private char currChar;
    private int currCount;

    public StringIterator(String compressedString) {
        this.s = compressedString;
        this.i = 0;
        this.currChar = 0;
        this.currCount = 0;
    }

    public char next() {
        if (!hasNext()) {
            return ' ';
        }
        if (currCount == 0) {
            currChar = s.charAt(i);
            i++;
            int start = i;
            while (i < s.length() && Character.isDigit(s.charAt(i))) {
                i++;
            }
            currCount = Integer.parseInt(s.substring(start, i));
        }
        currCount--;
        return currChar;
    }

    public boolean hasNext() {
        return i < s.length() || currCount > 0;
    }
}
