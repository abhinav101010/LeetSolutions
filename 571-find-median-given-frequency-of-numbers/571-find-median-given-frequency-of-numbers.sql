SELECT AVG(num) AS median
FROM (
    SELECT num,
           SUM(frequency) OVER (ORDER BY num) AS cum_freq
    FROM Numbers
) t
WHERE cum_freq >= (SELECT (SUM(frequency)+1)/2 FROM Numbers)
  AND cum_freq <= (SELECT (SUM(frequency)+2)/2 FROM Numbers)
