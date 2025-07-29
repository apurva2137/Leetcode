# Write your MySQL query statement below
select distinct(l1.num ) as ConsecutiveNums
from Logs l1
join Logs l2 on l1.id + 1 = l2.id and l1.num = l2.num
join Logs l3 on l1.id + 2 = l3.id and l1.num = l3.num