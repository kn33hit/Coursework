EXE = Lab10.out
OBJS = Residence.o House.o ResidenceDriver.o Tent.o Apartment.o
CXXFLAGS = -Wall

$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXE)

Residence.o: Residence.cpp Residence.h
ResidenceDriver.o: ResidenceDriver.cpp House.h Residence.h Apartment.h Tent.h
House.o: House.cpp House.h Residence.h
Tent.o: Tent.cpp Tent.h Residence.h
Apartment.o: Apartment.cpp Apartment.h Residence.h

.PHONY: clean
clean:
	-rm -f $(OBJS) $(EXE)