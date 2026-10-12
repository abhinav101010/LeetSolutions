/*
Trips and Users - SQL Solution:
SELECT t.Request_at AS Day,
       ROUND(SUM(CASE WHEN t.Status != 'completed' THEN 1 ELSE 0 END) / COUNT(*), 2) AS 'Cancellation Rate'
FROM Trips t
JOIN Users c ON t.Client_Id = c.Users_Id AND c.Banned = 'No'
JOIN Users d ON t.Driver_Id = d.Users_Id AND d.Banned = 'No'
WHERE t.Request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.Request_at
ORDER BY t.Request_at;
*/

class Solution {
public:
    string tripsAndUsers() {
        return R"(
            SELECT t.Request_at AS Day,
                   ROUND(SUM(CASE WHEN t.Status != 'completed' THEN 1 ELSE 0 END) / COUNT(*), 2) AS 'Cancellation Rate'
            FROM Trips t
            JOIN Users c ON t.Client_Id = c.Users_Id AND c.Banned = 'No'
            JOIN Users d ON t.Driver_Id = d.Users_Id AND d.Banned = 'No'
            WHERE t.Request_at BETWEEN '2013-10-01' AND '2013-10-03'
            GROUP BY t.Request_at
            ORDER BY t.Request_at;
        )";
    }
};