SELECT
    Id,
    Month,
    (
        SUM(Salary) OVER (PARTITION BY Id ORDER BY Month
                          ROWS BETWEEN 2 PRECEDING AND CURRENT ROW)
        - CASE WHEN Month = (SELECT MAX(Month) FROM Employee e2 WHERE e2.Id = Employee.Id) THEN Salary ELSE 0 END
    ) AS Salary
FROM Employee
ORDER BY Id, Month;
