select building, sum(capacity)
from classroom
group by building 
