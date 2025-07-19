SELECT
    e.name
FROM Employee e
JOIN 
(SELECT managerId,count(managerId)ct from Employee GROUP BY managerId)ea
ON e.id=ea.managerId
WHERE ea.ct>=5

