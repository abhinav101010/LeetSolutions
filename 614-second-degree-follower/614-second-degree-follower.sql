SELECT DISTINCT f2.followee
FROM follow f1
JOIN follow f2 ON f1.followee = f2.follower;
