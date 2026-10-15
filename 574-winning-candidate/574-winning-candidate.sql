SELECT Name AS winning_candidate
FROM Candidate
WHERE Vote = (SELECT MAX(Vote) FROM Candidate);
