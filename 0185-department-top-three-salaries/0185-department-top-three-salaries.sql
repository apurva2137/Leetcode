# Write your MySQL query statement below
with ranked as(
    select 
    d.name as Department,
    e.name as Employee,
    e.salary as Salary,
    dense_rank() over (
        partition by e.departmentId
        order by salary desc
    ) as rnk
    from employee e
    join department d on e.departmentId=d.Id
)

select Department , Employee, Salary
from ranked
where rnk<=3
