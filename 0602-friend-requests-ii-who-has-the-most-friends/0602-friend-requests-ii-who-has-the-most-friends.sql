SELECT 
    r2.accepter_id AS id,
    COUNT(*) AS num
FROM RequestAccepted r1
JOIN RequestAccepted r2 
    ON r1.requester_id = r2.accepter_id 
    AND r1.accepter_id = r2.requester_id
GROUP BY r2.accepter_id
ORDER BY num DESC
LIMIT 1;