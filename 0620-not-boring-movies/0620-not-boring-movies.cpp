#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Cinema {
    int id;
    string movie;
    string description;
    double rating;
};

class Solution {
public:
    vector<Cinema> notBoringMovies(vector<Cinema>& cinema) {
        vector<Cinema> result = cinema;
        result.erase(
            remove_if(result.begin(), result.end(),
                      [](const Cinema& c) {
                          return c.id % 2 == 0 || c.description == "boring";
                      }),
            result.end());
        sort(result.begin(), result.end(), [](const Cinema& a, const Cinema& b) {
            if (a.rating != b.rating) {
                return a.rating > b.rating; // descending
            }
            return a.id < b.id;
        });
        return result;
    }
};
