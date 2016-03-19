Book.o: src/Book.cpp src/Book.hpp
	g++ -Wall -O -c src/Book.cpp

UseBookClass.o: src/UseBookClass.cpp src/Book.hpp
	g++ -Wall -O -c src/UseBookClass.cpp

UseBookClass: UseBookClass.o Book.o
	g++ -Wall -lm -O UseBookClass.o Book.o -o UseBookClass
