! Neh N. Patel 
! Assignment 5  
! compile: gfortran -ffree-form a5.f
! run: ./a.out
      
program a5
!     Decalring some varibales 
      implicit none 
      integer:: y,i,j,k,f,x
      character:: name*20                  ! basically has a char with size 20
      real:: num

!     reading a file 
      print *, "Enter the name of the file: " 
      read *, name 
      open(10,file=name,access="sequential")
      
!      read(10,*) i
!      print *, i
      
      
      do
         read(10,*) i
         print *,i
      enddo   

!     writing to a file 
!      open(12,file='STDOUT')
!      write(1,*) i,j,k
!      print *, "Resutls are in STDOUT" 
         
end program a5
