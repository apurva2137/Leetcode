# Write your MySQL query statement below
select e.employee_id , e.name , count(e1.employee_id) as reports_count , round(avg(e1.age),0) as average_age
from employees e
left join employees e1 on e.employee_id = e1.reports_to
where e1.reports_to is not null
group by e.employee_id 
order by e.employee_id 

