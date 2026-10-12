class OrderedStream {
public:
    OrderedStream(int n) : stream(n + 1, ""), ptr(1) {}

    vector<string> insert(int idKey, string value) {
        stream[idKey] = value;
        vector<string> ans;

        while (ptr < (int)stream.size() && stream[ptr] != "") {
            ans.push_back(stream[ptr]);
            ptr++;
        }

        return ans;
    }

private:
    vector<string> stream;
    int ptr;
};