-- Last updated: 11/05/2026, 01:33:17
SELECT
    w1.id
FROM
    Weather w1
LEFT JOIN
    Weather w2
ON
    DATEDIFF(w1.recordDate, w2.recordDate) = 1
WHERE
    w1.temperature > w2.temperature ;