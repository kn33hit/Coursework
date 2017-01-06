all: DoubleHash.o LinearProbing.o QuadraticProbing.o Driver.o
	g++ -Wall -ansi DoubleHash.o LinearProbing.o QuadraticProbing.o Driver.o -o Driver.out

DoubleHash.o: DoubleHash.cpp DoubleHash.h 
	g++ -Wall -ansi -c DoubleHash.cpp

LinearProbing.o: LinearProbing.cpp LinearProbing.cpp 
	g++ -Wall -ansi -c LinearProbing.cpp

QuadraticProbing.o: QuadraticProbing.cpp QuadraticProbing.h
	g++ -Wall -ansi -c QuadraticProbing.cpp

Driver.o: Driver.cpp
	g++ -Wall -ansi -c Driver.cpp

make clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#[

make run:
	./Driver.out  $(FILE) $(N) $(INTERVAL) $(M) $(R)