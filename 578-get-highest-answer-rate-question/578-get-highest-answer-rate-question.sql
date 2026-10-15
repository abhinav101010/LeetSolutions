SELECT question_id
FROM SurveyLog
GROUP BY question_id
HAVING SUM(CASE WHEN Action = 'answer' THEN 1 ELSE 0 END) > 0
ORDER BY 
    SUM(CASE WHEN Action = 'answer' THEN 1.0 ELSE 0 END) /
    SUM(CASE WHEN Action = 'show' THEN 1.0 ELSE 0 END) DESC,
    question_id
LIMIT 1;
