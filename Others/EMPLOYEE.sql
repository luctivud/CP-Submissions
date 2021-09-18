EMPLOYEE

ename
dept
salary

select dept, sum(salary) as sumofsalary from EMPLOYEE groupby dept having sumofsalary > N