Proj4.out: Proj4.o Proj4Aux.o GridGame.o TicTacToe.o Reversi.o 
	g++ Proj4.o Proj4Aux.o GridGame.o TicTacToe.o Reversi.o -o Proj4.out 
Proj4.o: Proj4.cpp
	g++ -Wall -c Proj4.cpp
Proj4Aux.o: Proj4Aux.cpp Proj4Aux.h
	g++ -Wall -c Proj4Aux.cpp 
GridGame.o: GridGame.h GridGame.cpp
	g++ -Wall -c GridGame.cpp
TicTacToe.o: TicTacToe.h TicTacToe.cpp
	g++ -Wall -c TicTacToe.cpp
Reversi.o: Reversi.h Reversi.cpp 
	g++ -Wall -c Reversi.cpp