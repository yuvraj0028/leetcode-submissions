# Write your MySQL query statement below
DELETE p FROM person p, person q
WHERE p.id > q.id and p.email = q.email;