#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <tuple>
using namespace std;

struct FriendRequest {
    int sender_id;
    int send_to_id;
    string request_date;
};

struct RequestAccepted {
    int requester_id;
    int accepter_id;
    string accept_date;
};

class Solution {
public:
    string acceptanceRate(vector<FriendRequest>& requests, vector<RequestAccepted>& accepted) {
        set<pair<int,int>> reqSet;
        for (const auto& r : requests) {
            // store unique pairs (sender, receiver) - order matters as given
            reqSet.insert({r.sender_id, r.send_to_id});
        }
        set<pair<int,int>> accSet;
        for (const auto& a : accepted) {
            accSet.insert({a.requester_id, a.accepter_id});
        }
        // count accepted that are in requests? - "acceptance rate = number of (requester_id, accepter_id) accepted / number of (sender_id, send_to_id) requested"
        // they might not all match - but count distinct pairs in each
        long long totalReq = reqSet.size();
        if (totalReq == 0) return "0.00";
        long long totalAcc = 0;
        for (const auto& p : accSet) {
            if (reqSet.find(p) != reqSet.end()) {
                totalAcc++;
            }
        }
        double rate = (double)totalAcc / (double)totalReq;
        // round to 2 decimal places
        rate = round(rate * 100.0) / 100.0;
        // format to 2 decimals
        char buf[10];
        sprintf(buf, "%.2f", rate);
        return string(buf);
    }
};
