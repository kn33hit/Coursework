all : Driver.o Indexer.o Word.o BST.h dsexceptions.h Exceptions.h 
	g++ -Wall -ansi Driver.o  Indexer.o Word.o BST.h dsexceptions.h Exceptions.h -o Driver.out 

Driver.o:Driver.cpp
	g++ -Wall -ansi -c Driver.cpp 

Indexer.o:Indexer.cpp
	g++ -Wall -ansi -c Indexer.cpp

Word.o: Word.cpp
	g++ -Wall -ansi -c Word.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#[

run: 
	./Driver.out $(FILTER) $(DATA)
