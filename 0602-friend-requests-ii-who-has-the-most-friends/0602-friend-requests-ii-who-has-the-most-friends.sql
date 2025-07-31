# Write your MySQL query statement below
with frq as(
    select requester_id from RequestAccepted
    union all
    select accepter_id from RequestAccepted
)

select requester_id as id , count(*) as num
from frq
group by id
order by num desc 
limit 1

