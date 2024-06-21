# Write your MySQL query statement below
SELECT UNI.unique_id, E.name FROM Employees as E LEFT JOIN EmployeeUNI as UNI ON E.id = UNI.id;