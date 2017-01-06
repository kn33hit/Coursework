Proj2.out: Proj2.o Blackjack.o Deck.o Hand.o Player.o Card.o
	g++ -Wall Proj2.o Blackjack.o Deck.o Hand.o Player.o Card.o -o Proj2.out

Proj2.o: Proj2.cpp Blackjack.h
	g++ -Wall -c Proj2.cpp

Blackjack.o: Blackjack.cpp Blackjack.h Player.h Hand.h
	g++ -Wall -c Blackjack.cpp

Deck.o: Deck.cpp Deck.h Card.h
	g++ -Wall -c Deck.cpp

Card.o: Card.cpp Card.h
	g++ -Wall -c Card.cpp

Hand.o: Hand.cpp Hand.h
	g++ -Wall -c Hand.cpp

Player.o: Player.cpp Player.h Hand.h
	g++ -Wall -c Player.cpp