select course_id, sec_id, semester, building, day, start_hr, start_min
from section natural join time_slot
where time_slot_id = time_slot_id and year = 2010
