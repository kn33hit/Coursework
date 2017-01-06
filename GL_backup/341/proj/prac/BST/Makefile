Driver.out: Driver.o BST.h
	g++ -Wall -ansi BST.h Driver.o -o Driver.out

Driver.o: Driver.cpp
	g++ -Wall -ansi -c Driver.cpp

clean:
	rm -f *.o driver.out *~ *.gch

run: 
	./Driver.out
