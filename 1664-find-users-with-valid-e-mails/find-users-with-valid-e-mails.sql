# Write your MySQL query statement below
select * from users
where mail regexp '^[A-Za-a][A-Za-a0-9_\.\-]*@leetcode[\.]com$';