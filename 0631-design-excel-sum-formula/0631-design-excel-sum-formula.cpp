#include <vector>
#include <string>
using namespace std;

class Excel {
private:
    int H;
    int W;
    vector<vector<int>> val;
    vector<vector<vector<vector<int>>>> formula; // formula[r][c] vector of {r1,c1,r2,c2}

    vector<vector<int>> parse(const string& s) {
        vector<vector<int>> res;
        if (s.find(':') == string::npos) {
            int col = s[0] - 'A';
            int row = stoi(s.substr(1)) - 1;
            res.push_back({row, col, row, col});
        } else {
            size_t pos = s.find(':');
            string left = s.substr(0, pos);
            string right = s.substr(pos+1);
            int c1 = left[0] - 'A';
            int r1 = stoi(left.substr(1)) - 1;
            int c2 = right[0] - 'A';
            int r2 = stoi(right.substr(1)) - 1;
            if (r1 > r2) swap(r1, r2);
            if (c1 > c2) swap(c1, c2);
            res.push_back({r1, c1, r2, c2});
        }
        return res;
    }

public:
    Excel(int height, char width) {
        H = height;
        W = width - 'A' + 1;
        val.assign(H, vector<int>(W, 0));
        formula.assign(H, vector<vector<vector<int>>>(W));
    }

    void set(int row, char column, int val) {
        int r = row - 1;
        int c = column - 'A';
        this->val[r][c] = val;
        formula[r][c].clear();
    }

    int get(int row, char column) {
        int r = row - 1;
        int c = column - 'A';
        if (formula[r][c].empty()) {
            return val[r][c];
        }
        int total = 0;
        for (auto& rc : formula[r][c]) {
            int r1 = rc[0], c1 = rc[1], r2 = rc[2], c2 = rc[3];
            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    total += get(i + 1, 'A' + j);
                }
            }
        }
        return total;
    }

    int sum(int row, char column, vector<string>& numbers) {
        int r = row - 1;
        int c = column - 'A';
        vector<vector<int>> list;
        for (auto& num : numbers) {
            auto parsed = parse(num);
            list.insert(list.end(), parsed.begin(), parsed.end());
        }
        formula[r][c] = list;
        return get(row, column);
    }
};
