# Write your MySQL query statement below
select p.product_name,SUM(unit) as unit
from Orders o
left join Products p on o.product_id=p.product_id
where YEAR(order_date)='2020' and MONTH(order_date)='02'
group by product_name
having unit>=100;