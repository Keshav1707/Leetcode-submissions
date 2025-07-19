# Write your MySQL query statement below
SELECT 
    w.id 
FROM Weather w
JOIN Weather wb
WHERE
    DATEDIFF(w.recordDate,wb.recordDate)=1
    AND
    w.temperature > wb.temperature