#include <vector>
#include <string>
using namespace std;

struct Seat {
    int id;
    string student;
};

class Solution {
public:
    vector<Seat> exchangeSeats(vector<Seat>& seats) {
        vector<Seat> res = seats;
        int n = res.size();
        for (int i = 0; i < n - 1; i += 2) {
            // swap students between i and i+1, but adjust by id positions?
            // The result should have ids reordered according to CASE in SQL
            // SQL produces new id values and corresponding students
            swap(res[i].student, res[i+1].student);
        }
        // But wait - SQL changes id values based on logic, not just swaps adjacent students?
        // Let us look: CASE gives new id, student stays same - so we return (new_id, student)
        // So we need to create result with new ids
        vector<pair<int, string>> temp(n);
        for (int i = 0; i < n; i++) {
            int newId;
            int id = seats[i].id;
            if (id % 2 == 1 && id != n) { // n is total count? SQL does MAX(id)
                newId = id + 1;
            } else if (id % 2 == 0) {
                newId = id - 1;
            } else {
                newId = id; // odd and last
            }
            temp[i] = {newId, seats[i].student};
        }
        vector<Seat> result(n);
        // sort by newId
        sort(temp.begin(), temp.end());
        for (int i = 0; i < n; i++) {
            result[i] = {temp[i].first, temp[i].second};
        }
        return result;
    }
};
