all: driver.o Node.o SplayTree.h HashedSplays.h Util.o dsexceptions.h Exceptions.h
	g++ -Wall -ansi driver.o Node.o SplayTree.h HashedSplays.h Util.o dsexceptions.h Exceptions.h -o Driver.out 

driver.o: driver.cpp
	g++ -Wall -ansi -c driver.cpp

Node.o: Node.h Node.cpp 
	g++ -Wall -ansi -c Node.cpp

Util.o: Util.h Util.cpp
	g++ -Wall -ansi -c Util.cpp

make clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#[

make run: 
	./Driver.out $(DATA) 