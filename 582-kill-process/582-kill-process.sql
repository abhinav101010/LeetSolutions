WITH RECURSIVE kill AS (
    SELECT Id FROM Process WHERE Id = <kill_value>
    UNION ALL
    SELECT p.Id FROM Process p
    JOIN kill k ON p.ParentId = k.Id
)
SELECT Id FROM kill;
