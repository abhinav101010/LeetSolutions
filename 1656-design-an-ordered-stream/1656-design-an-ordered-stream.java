class OrderedStream {
    private String[] stream;
    private int ptr;

    public OrderedStream(int n) {
        stream = new String[n + 1];
        ptr = 1;
    }

    public String[] insert(int idKey, String value) {
        stream[idKey] = value;
        java.util.List<String> ans = new java.util.ArrayList<>();

        while (ptr < stream.length && stream[ptr] != null) {
            ans.add(stream[ptr]);
            ptr++;
        }

        return ans.toArray(new String[0]);
    }
}