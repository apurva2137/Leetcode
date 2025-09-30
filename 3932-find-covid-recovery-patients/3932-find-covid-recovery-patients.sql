# Write your MySQL query statement below
select p.patient_id , p.patient_name , p.age , datediff(min(c1.test_date) , min(c.test_date)) as recovery_time
from patients p
join covid_tests c on p.patient_id = c.patient_id 
join covid_tests c1 on c.patient_id = c1.patient_id
where c.test_id < c1.test_id and c.result = 'Positive' and c1.result = 'Negative' 
group by c.patient_id
order by recovery_time , patient_name 
