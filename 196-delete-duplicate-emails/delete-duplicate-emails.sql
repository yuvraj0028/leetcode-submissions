DELETE p
FROM person p
JOIN (
    SELECT MIN(id) as min_id, email
    FROM person
    GROUP BY email
) q
ON p.email = q.email AND p.id > q.min_id;
