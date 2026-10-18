SELECT
    MAX(CASE WHEN geography = 'America' THEN student_name END) AS America,
    MAX(CASE WHEN geography = 'Asia' THEN student_name END) AS Asia,
    MAX(CASE WHEN geography = 'Europe' THEN student_name END) AS Europe
FROM (
    SELECT student_name, geography,
           ROW_NUMBER() OVER (PARTITION BY geography ORDER BY student_name) AS rn
    FROM Students
) t
GROUP BY rn
ORDER BY rn;
