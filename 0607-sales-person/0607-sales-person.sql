# Write your MySQL query statement below
select s.name
from SalesPerson s
where sales_id not in(
select sales_id from 
Orders o
left join Company c on o.com_id = c.com_id
where name = "RED" )

