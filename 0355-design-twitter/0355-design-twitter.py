from typing import List, Dict, Set
import heapq

class Twitter:

    class Tweet:
        def __init__(self, tweetId: int, time: int):
            self.tweetId = tweetId
            self.time = time

    def __init__(self):
        self.tweets: Dict[int, List[Twitter.Tweet]] = {}
        self.following: Dict[int, Set[int]] = {}
        self.timestamp = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        if userId not in self.tweets:
            self.tweets[userId] = []
        self.tweets[userId].append(self.Tweet(tweetId, self.timestamp))
        self.timestamp += 1

    def getNewsFeed(self, userId: int) -> List[int]:
        all_tweets = []

        # Include the user's own tweets.
        if userId in self.tweets:
            all_tweets.extend(self.tweets[userId])

        # Include tweets from followed users.
        for followeeId in self.following.get(userId, set()):
            if followeeId in self.tweets:
                all_tweets.extend(self.tweets[followeeId])

        # Sort tweets from newest to oldest.
        all_tweets.sort(key=lambda t: t.time, reverse=True)

        # Return at most 10 tweet IDs.
        return [t.tweetId for t in all_tweets[:10]]

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId == followeeId:
            return
        if followerId not in self.following:
            self.following[followerId] = set()
        self.following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followerId in self.following:
            self.following[followerId].discard(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)