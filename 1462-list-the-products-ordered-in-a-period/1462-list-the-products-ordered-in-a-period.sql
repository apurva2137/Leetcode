# Write your MySQL query statement below
select p.product_name,SUM(unit) as unit
from Orders o
left join Products p on o.product_id=p.product_id
where order_date like '2020-02-%' 
group by product_name
having unit>=100;