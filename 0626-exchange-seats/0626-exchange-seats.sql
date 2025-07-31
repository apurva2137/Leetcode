# Write your MySQL query statement below
select s1.id , coalesce(s2.student , s1.student ) as student
from seat s1
left join seat s2 on 
(s1.id % 2 = 1 and s2.id = s1.id + 1) or (s1.id % 2 = 0 and s2.id = s1.id -1 )