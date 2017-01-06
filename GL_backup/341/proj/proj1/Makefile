all: Driver.o TrafficSim.o IntersectionFlowRate.o Vehicle.o Linked_List.o ResultVehicle.o
	g++ -ansi -Wall Driver.o TrafficSim.o IntersectionFlowRate.o Vehicle.o Linked_List.o ResultVehicle.o -o output.out

ResultVehicle.o: ResultVehicle.cpp
	g++ -ansi -Wall -c ResultVehicle.cpp

Linked_List.o: Linked_List.cpp
	g++ -ansi -Wall -c Linked_List.cpp

Vehicle.o: Vehicle.cpp
	g++ -ansi -Wall -c Vehicle.cpp

IntersectionFlowRate.o: IntersectionFlowRate.cpp
	g++ -ansi -Wall -c IntersectionFlowRate.cpp

TrafficSim.o: TrafficSim.cpp
	g++ -ansi -Wall -c TrafficSim.cpp

Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp


clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#[


run:
	./output.out $(STRING)