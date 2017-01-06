select name, year, student.id
from student, takes  
where student.ID = takes.ID
having year > 2009
group by name, year, student.id
