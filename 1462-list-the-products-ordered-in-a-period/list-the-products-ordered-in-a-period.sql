# Write your MySQL query statement below
select product_name, sum(unit) as unit
from products inner join orders using(product_id)
where month(order_date) = 2 and year(order_date) = 2020
group by product_name
having unit >= 100;