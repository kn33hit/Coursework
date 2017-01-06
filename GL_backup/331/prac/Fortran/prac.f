
 program prac

!      USE, INTRINSIC :: ISO_C_BINDING, ONLY: C_INT
      INTEGER, PARAMETER :: unit = 10
      INTEGER :: data
      character:: name*20                  ! basically has a char with size 20

      print*, "Enter the file name"
      read*, name
!***
      open(unit , file=name , ACCESS='STREAM', FORM='UNFORMATTED')
      read (unit) data
      close(unit)
      print "(' ',I0)", data
end program prac
 
!http://stackoverflow.com/questions/11569644/can-fortran-read-bytes-directly-from-a-binary-file
