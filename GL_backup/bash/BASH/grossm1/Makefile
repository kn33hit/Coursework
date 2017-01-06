Proj2.out: Proj2.o Blackjack.o Player.o Hand.o Deck.o Card.o
	g++ -ansi -Wall -o Proj2.out Proj2.o Blackjack.o Player.o Hand.o Deck.o Card.o

Proj2.o: Blackjack.h Player.h Hand.h Deck.h Proj2.cpp
	g++ -ansi -Wall -c Proj2.cpp

Blackjack.o: Blackjack.h Blackjack.cpp Player.h Hand.h Deck.h
	g++ -ansi -Wall -c Blackjack.cpp

Player.o: Player.h Hand.h Player.cpp
	g++ -ansi -Wall -c Player.cpp

Hand.o: Hand.h Hand.cpp Card.h
	g++ -ansi -Wall -c Hand.cpp

Deck.o: Deck.h Deck.cpp Card.h
	g++ -ansi -Wall -c Deck.cpp

Card.o: Card.h Card.cpp
	g++ -ansi -Wall -c Card.cpp