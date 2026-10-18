import java.util.*;

class Solution {
    static class Tweet {
        int tweet_id;
        String content;
        
        public Tweet(int tweet_id, String content) {
            this.tweet_id = tweet_id;
            this.content = content;
        }
    }
    
    public List<Integer> invalidTweets(List<Tweet> tweets) {
        List<Integer> result = new ArrayList<>();
        for (Tweet t : tweets) {
            if (t.content != null && t.content.length() > 15) {
                result.add(t.tweet_id);
            }
        }
        return result;
    }
}
