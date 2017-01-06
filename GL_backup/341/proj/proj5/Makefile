all: Driver.o Graph.o 
	g++ -Wall -ansi Driver.o Graph.o -o Driver.out 

Driver.o: Driver.cpp
	g++ -Wall -ansi -c Driver.cpp

Graph.o: Graph.h Graph.cpp
	g++ -Wall -ansi -c Graph.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#[

run:
	./Driver.out $(FILE)

