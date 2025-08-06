# Write your MySQL query statement below
with imp as(
    select distinct student_id , subject,
    first_value(score) over(partition by student_id , subject order by exam_date) first_score,
    first_value(score) over(partition by student_id , subject order by exam_date desc) latest_score
    from scores
)

select * from imp 
where first_score < latest_score 
order by student_id , subject

