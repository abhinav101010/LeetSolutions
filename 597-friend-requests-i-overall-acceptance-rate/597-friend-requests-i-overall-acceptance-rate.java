import java.text.DecimalFormat;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class FriendRequest {
    int sender_id;
    int send_to_id;
    String request_date;
}

class RequestAccepted {
    int requester_id;
    int accepter_id;
    String accept_date;
}

class Pair {
    int a, b;
    Pair(int a, int b) {
        this.a = a; this.b = b;
    }
    public int hashCode() {
        return (a * 131542391) ^ b;
    }
    public boolean equals(Object o) {
        if (!(o instanceof Pair)) return false;
        Pair p = (Pair)o;
        return a == p.a && b == p.b;
    }
}

class Solution {
    public String acceptanceRate(List<FriendRequest> requests, List<RequestAccepted> accepted) {
        Set<Pair> reqSet = new HashSet<>();
        for (FriendRequest r : requests) {
            reqSet.add(new Pair(r.sender_id, r.send_to_id));
        }
        Set<Pair> accSet = new HashSet<>();
        for (RequestAccepted a : accepted) {
            accSet.add(new Pair(a.requester_id, a.accepter_id));
        }
        if (reqSet.isEmpty()) return "0.00";
        long totalAcc = 0;
        for (Pair p : accSet) {
            if (reqSet.contains(p)) {
                totalAcc++;
            }
        }
        double rate = (double)totalAcc / (double)reqSet.size();
        DecimalFormat df = new DecimalFormat("0.00");
        return df.format(Math.round(rate * 100.0) / 100.0);
    }
}
