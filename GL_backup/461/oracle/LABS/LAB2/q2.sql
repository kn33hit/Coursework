select course_id, building, room_number, capacity
from section natural join classroom 
where building = building and room_number = room_number and year = 2010
