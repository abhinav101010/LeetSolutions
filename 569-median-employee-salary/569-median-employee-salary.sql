SELECT Id, Company, Salary
FROM (
    SELECT Id, Company, Salary,
           ROW_NUMBER() OVER (PARTITION BY Company ORDER BY Salary) AS rn_asc,
           ROW_NUMBER() OVER (PARTITION BY Company ORDER BY Salary DESC) AS rn_desc
    FROM Employee
) x
WHERE rn_asc IN (rn_desc, rn_desc-1, rn_desc+1);
