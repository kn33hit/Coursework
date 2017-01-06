CPPFLAGS = -Wall
EXE = Proj2.out
OBJS = Proj2.o Blackjack.o Deck.o  Card.o Player.o Hand.o

$(EXE): $(OBJS)
	g++ $(CPPFLAGS) $(OBJS) -o $(EXE)

.PHONY: clean
clean:
	-rm -f $(OBJS) $(EXE)
