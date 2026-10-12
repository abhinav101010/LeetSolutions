/*
Rising Temperature - SQL solution:
SELECT w1.Id
FROM Weather w1
JOIN Weather w2 ON DATEDIFF(w1.RecordDate, w2.RecordDate) = 1
WHERE w1.Temperature > w2.Temperature;
*/

import java.util.*;

class Solution {
    public String risingTemperature() {
        return "SELECT w1.Id FROM Weather w1 JOIN Weather w2 ON DATEDIFF(w1.RecordDate, w2.RecordDate) = 1 WHERE w1.Temperature > w2.Temperature;";
    }
}