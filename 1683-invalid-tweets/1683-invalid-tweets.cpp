#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Tweet {
    int tweet_id;
    string content;
};

class Solution {
public:
    vector<int> invalidTweets(vector<Tweet>& tweets) {
        vector<int> result;
        for (const auto& t : tweets) {
            if (t.content.size() > 15) {
                result.push_back(t.tweet_id);
            }
        }
        return result;
    }
};
