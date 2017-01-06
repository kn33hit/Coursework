program read

      integer m,n
      parameter (m=10, n=10)
      real x(m,n)

!     open direct access unformatted file with records sized for a single row
!     note how we can read in the data differently from how it was written.
!     You just need to make recl the smallest thing you will read and adjust
!     your read statements accordingly

      open (unit=1,file='a.txt',form='unformatted',access='direct',recl=m*4)

!     read in each row as a single record

      do j = 1, n
         read (1,rec=j) (x(i,j), i=1,m)
         print *, j
      end do

end program read

! http://www.atmos.washington.edu/~salathe/osx_unix/endian.html
