# Write your MySQL query statement below
SELECT firstName,lastName,city,state from 
Person Left Join Address on person.personId = address.personId ;