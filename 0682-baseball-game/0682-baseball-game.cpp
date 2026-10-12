class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        for (const auto& opr : operations) {
            if (opr == "C") {
                scores.pop();
            } else if (opr == "D") {
                int last = scores.top();
                scores.push(last * 2);
            } else if (opr == "+") {
                int last = scores.top();
                scores.pop();
                int prev = scores.top();
                int sum = last + prev;
                scores.push(last);
                scores.push(sum);
            } else {
                scores.push(stoi(opr));
            }
        }
        int total = 0;
        while (!scores.empty()) {
            total += scores.top();
            scores.pop();
        }
        return total;
    }
};
