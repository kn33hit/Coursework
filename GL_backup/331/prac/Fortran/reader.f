program reader
 integer:: a(512), i, result
 open(unit = 8, file="a.txt", access="stream",form="unformatted")
! read all of a
 read(8) a
 do i = 1,1024
   if (a(i) .ne. i-1) print *,'error at ', i
 enddo
! read the file backward
 do i = 1024,1,-1
   read(8, pos=(i-1)*4+1) result
   if (result .ne. i-1) print *,'error at ', i
 enddo
 close(8)
end

!https://docs.oracle.com/cd/E19059-01/stud.9/817-6694/2_io.html
