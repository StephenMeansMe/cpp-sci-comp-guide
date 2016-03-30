BASE_DIR = base
CPPFLAGS = -ansi -Wall -pedantic
LDFLAGS  =

student.o: problems/student.cpp problems/student.hpp
	g++ -I $(BASE_DIR) $(CPPFLAGS) -c -O problems/student.cpp

pr07_01.o: problems/pr07_01.cpp problems/student.hpp
	g++ -I $(BASE_DIR) $(CPPFLAGS) -c -O problems/pr07_01.cpp

pr07_01: pr07_01.o student.o
	g++ -I $(BASE_DIR) $(LDFLAGS) -o pr07_01 -O pr07_01.o student.o
