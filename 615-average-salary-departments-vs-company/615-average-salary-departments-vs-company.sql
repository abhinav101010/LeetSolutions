SELECT e.Company
FROM Employee e
GROUP BY e.Company
HAVING AVG(e.Salary) < 
    (
        SELECT AVG(m.Salary)
        FROM Employee m
        WHERE m.Id IN (SELECT DISTINCT ManagerId FROM Employee WHERE ManagerId IS NOT NULL AND Company = e.Company)
          AND m.Company = e.Company
    );
