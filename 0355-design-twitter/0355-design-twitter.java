import java.util.*;

class Twitter {

    class Tweet {
        int tweetId;
        int time;

        Tweet(int tweetId, int time) {
            this.tweetId = tweetId;
            this.time = time;
        }
    }

    private Map<Integer, List<Tweet>> tweets;
    private Map<Integer, Set<Integer>> following;
    private int timestamp;

    public Twitter() {
        tweets = new HashMap<>();
        following = new HashMap<>();
        timestamp = 0;
    }

    public void postTweet(int userId, int tweetId) {
        tweets.putIfAbsent(userId, new ArrayList<>());

        tweets.get(userId).add(new Tweet(tweetId, timestamp++));
    }

    public List<Integer> getNewsFeed(int userId) {
        List<Tweet> allTweets = new ArrayList<>();

        // Include the user's own tweets.
        if (tweets.containsKey(userId)) {
            allTweets.addAll(tweets.get(userId));
        }

        // Include tweets from followed users.
        Set<Integer> users = following.getOrDefault(
            userId, Collections.emptySet()
        );

        for (int followeeId : users) {
            if (tweets.containsKey(followeeId)) {
                allTweets.addAll(tweets.get(followeeId));
            }
        }

        // Sort tweets from newest to oldest.
        allTweets.sort((a, b) -> Integer.compare(b.time, a.time));

        // Return at most 10 tweet IDs.
        List<Integer> feed = new ArrayList<>();

        for (int i = 0; i < Math.min(10, allTweets.size()); i++) {
            feed.add(allTweets.get(i).tweetId);
        }

        return feed;
    }

    public void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }

        following.putIfAbsent(followerId, new HashSet<>());
        following.get(followerId).add(followeeId);
    }

    public void unfollow(int followerId, int followeeId) {
        if (following.containsKey(followerId)) {
            following.get(followerId).remove(followeeId);
        }
    }
}