select instructor.name 
from instructor,student, advisor  
where instructor.id = advisor.i_id and advisor.s_id = student.id and student.dept_name = 'Comp. Sci.'

