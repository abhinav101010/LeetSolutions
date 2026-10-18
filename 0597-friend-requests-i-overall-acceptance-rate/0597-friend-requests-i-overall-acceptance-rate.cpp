#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct FriendRequest {
    int senderId;
    int sendToId;
};

struct RequestAccepted {
    int requesterId;
    int accepterId;
};

class Solution {
public:
    double friendRequests(int n, vector<FriendRequest>& requests, vector<RequestAccepted>& accepts) {
        // Build set of unique accepted pairs (or count unique)
        // Count total requests (unique sender, sendTo pairs?)
        // Count accepted (unique requester, accepter pairs?)
        // Leetcode states: "Note that, even if a request is made multiple times, it only counts once. 
        // If a request is accepted more than once, it only counts once."
        unordered_set<string> requestSet;
        for (const auto& r : requests) {
            requestSet.insert(to_string(r.senderId) + "," + to_string(r.sendToId));
        }
        unordered_set<string> acceptSet;
        for (const auto& a : accepts) {
            acceptSet.insert(to_string(a.requesterId) + "," + to_string(a.accepterId));
        }
        if (requestSet.empty()) {
            return 0.0;
        }
        // Count how many requests were accepted - intersection
        int acceptedCount = 0;
        for (const auto& req : requestSet) {
            if (acceptSet.find(req) != acceptSet.end()) {
                acceptedCount++;
            }
        }
        double rate = (double)acceptedCount / (double)requestSet.size();
        return rate;
    }
};
