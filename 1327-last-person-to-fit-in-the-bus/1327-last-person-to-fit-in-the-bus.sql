# Write your MySQL query statement below
with fitsum as(
    select person_name , 
    sum(weight) over (order by turn) as totsum
    from queue
)

select person_name 
from fitsum
where totsum <= 1000
order by totsum desc
limit 1