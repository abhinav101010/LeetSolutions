import java.util.*;

class Solution {
    static class FriendRequest {
        int senderId;
        int sendToId;
        
        public FriendRequest(int senderId, int sendToId) {
            this.senderId = senderId;
            this.sendToId = sendToId;
        }
    }
    
    static class RequestAccepted {
        int requesterId;
        int accepterId;
        
        public RequestAccepted(int requesterId, int accepterId) {
            this.requesterId = requesterId;
            this.accepterId = accepterId;
        }
    }
    
    public double friendRequests(int n, List<FriendRequest> requests, List<RequestAccepted> accepts) {
        Set<String> requestSet = new HashSet<>();
        for (FriendRequest r : requests) {
            requestSet.add(r.senderId + "," + r.sendToId);
        }
        Set<String> acceptSet = new HashSet<>();
        for (RequestAccepted a : accepts) {
            acceptSet.add(a.requesterId + "," + a.accepterId);
        }
        if (requestSet.isEmpty()) {
            return 0.0;
        }
        int acceptedCount = 0;
        for (String req : requestSet) {
            if (acceptSet.contains(req)) {
                acceptedCount++;
            }
        }
        return (double) acceptedCount / (double) requestSet.size();
    }
}
