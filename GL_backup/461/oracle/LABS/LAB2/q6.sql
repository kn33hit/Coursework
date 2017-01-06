select dept_name, max(salary)
from instructor
group by dept_name 
