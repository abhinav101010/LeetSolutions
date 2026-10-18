SELECT d.Name AS Department_Name, COUNT(s.Id) AS Student_count
FROM Departments d
LEFT JOIN Students s ON d.Id = s.Department_id
GROUP BY d.Id, d.Name
ORDER BY Student_count DESC, d.Name;
