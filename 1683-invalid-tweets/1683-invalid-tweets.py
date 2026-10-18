from typing import List

class Tweet:
    def __init__(self, tweet_id: int, content: str):
        self.tweet_id = tweet_id
        self.content = content

class Solution:
    def invalidTweets(self, tweets: List[Tweet]) -> List[int]:
        result = []
        for t in tweets:
            if len(t.content) > 15:
                result.append(t.tweet_id)
        return result
