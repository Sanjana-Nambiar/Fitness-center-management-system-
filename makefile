output: assignment1.o admins.o members.o fitnessClass.o
	g++ assignment1.o admins.o members.o fitnessClass.o -o output

admins.o: admins.cpp admins.h members.cpp members.h fitnessClass.cpp fitnessClass.h
	g++ -c admins.cpp members.cpp fitnessClass.cpp

members.o: members.cpp members.h fitnessClass.cpp fitnessClass.h
	g++ -c members.cpp fitnessClass.cpp

fitnessClass.o: fitnessClass.cpp fitnessClass.h
	g++ -c fitnessClass.cpp

assignment1.o: assignment1.cpp
	g++ -c assignment1.cpp

clean:
	rm *.o output