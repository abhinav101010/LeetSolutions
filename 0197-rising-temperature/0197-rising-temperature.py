# Rising Temperature - SQL solution
# SELECT w1.Id
# FROM Weather w1
# JOIN Weather w2 ON DATEDIFF(w1.RecordDate, w2.RecordDate) = 1
# WHERE w1.Temperature > w2.Temperature;

class Solution:
    def risingTemperature(self):
        """
        SQL:
        SELECT w1.Id
        FROM Weather w1
        JOIN Weather w2 ON DATEDIFF(w1.RecordDate, w2.RecordDate) = 1
        WHERE w1.Temperature > w2.Temperature;
        """
        pass