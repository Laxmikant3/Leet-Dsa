# Write your MySQL query statement below
SELECT email as Email from person 
group By email having count(email)>1;