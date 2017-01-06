select name, course_id 
from instructor 
inner join teaches
on instructor.ID = teaches.ID
order by name
