CPPFLAGS = -Wall
EXE=Proj2.out
OBJS = Card.o Deck.o Hand.o Player.o Blackjack.o Proj2.o
$(EXE): $(OBJS)
	g++ $(CPPFLAGS) $(OBJS) -o $(EXE)
.PHONY: clean
clean:
	-rm -f $(OBJS) $(EXE)