CPPFLAGS = -ansi  -Wall

lab6.out:: lab6.o fraction.o 
	g++ -o lab6 fraction.o lab6.o 

lab6.o: lab6.cpp 
	g++ -c lab6.cpp
 
fraction.o: fraction.cpp fraction.h
	g++ -c fraction.cpp 