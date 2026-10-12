SELECT id, visit_date, people
FROM Stadium
WHERE people >= 100
AND id IN (
    SELECT s1.id
    FROM Stadium s1, Stadium s2, Stadium s3
    WHERE s1.people >= 100 AND s2.people >= 100 AND s3.people >= 100
    AND (
        (s1.id = s2.id - 1 AND s2.id = s3.id - 1) OR
        (s1.id = s2.id + 1 AND s2.id = s3.id + 1) OR
        (s2.id = s1.id - 1 AND s1.id = s3.id - 1) OR
        (s2.id = s1.id + 1 AND s1.id = s3.id + 1) OR
        (s3.id = s1.id - 1 AND s1.id = s2.id - 1) OR
        (s3.id = s1.id + 1 AND s1.id = s2.id + 1)
    )
)
ORDER BY visit_date;