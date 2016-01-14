# ============================================================================ #
# GUIDE TO SCIENTIFIC COMPUTING IN C++ -- CHAPTER 05 EXERCISES                 #
# ---------------------------------------------------------------------------- #
# Makefile Parameters

CC=g++
CFLAGS=-c -Wall
LDFLAGS=
ALL_1=ch05ex01 ch05ex02 ch05ex03 ch05ex04 ch05ex05 
ALL_2=ch05ex06 ch05ex07 ch05ex08 ch05ex09 ch05ex10
ARRAY_H_1=src/allocate_array.h src/delete_array.h 
ARRAY_H_2=src/populate_values.h src/print_array.h
ARRAY_O_1=$(ARRAY_H_1:.h=.o)
ARRAY_O_2=$(ARRAY_H_2:.h=.o)

# ---------------------------------------------------------------------------- #
# Generic Compilations

all: $(ALL)

clean:
	rm *.o

# ---------------------------------------------------------------------------- #
# CH. 05, EXERCISE 01
 
pointer_value.o: src/pointer_value.cpp src/pointer_value.h
	$(CC) $(CFLAGS) src/pointer_value.cpp
ch05ex01.o: src/ch05ex01.cpp src/pointer_value.h
	$(CC) $(CFLAGS) src/ch05ex01.cpp
ch05ex01: ch05ex01.o pointer_value.o
	$(CC) $(LDFLAGS) ch05ex01.o pointer_value.o -o ch05ex01

# ---------------------------------------------------------------------------- #
# CH. 05, EXERCISE 02

pointer_change.o: src/pointer_change.cpp src/pointer_change.h
	$(CC) $(CFLAGS) src/pointer_change.cpp
ch05ex02.o: src/ch05ex02.cpp src/pointer_change.h
	$(CC) $(CFLAGS) src/ch05ex02.cpp
ch05ex02: ch05ex02.o pointer_change.o
	$(CC) $(LDFLAGS) ch05ex02.o pointer_change.o -o ch05ex02

# ---------------------------------------------------------------------------- #
# CH. 05, EXERCISE 03

swap_vars.o: src/swap_vars.cpp src/swap_vars.h
	$(CC) $(CFLAGS) src/swap_vars.cpp
ch05ex03.o: src/ch05ex03.cpp src/swap_vars.h
	$(CC) $(CFLAGS) src/ch05ex03.cpp
ch05ex03: ch05ex03.o swap_vars.o
	$(CC) $(LDFLAGS) ch05ex03.o swap_vars.o -o ch05ex03

# ---------------------------------------------------------------------------- #
# CH. 05, EXERCISE 04

calc_mean.o: src/calc_mean.cpp src/calc_mean.h
	$(CC) $(CFLAGS) src/calc_mean.cpp
calc_sdev.o: src/calc_sdev.cpp src/calc_sdev.h
	$(CC) $(CFLAGS) src/calc_sdev.cpp
ch05ex04.o: src/ch05ex04.cpp src/calc_mean.h src/calc_sdev.h
	$(CC) $(CFLAGS) src/ch05ex04.cpp
ch05ex04: ch05ex05.o calc_mean.o calc_sdev.o
	$(CC) $(LDFLAGS) ch05ex04.o calc_mean.o calc_sdev.o -o ch05ex04

# ---------------------------------------------------------------------------- #
# ARRAY COMPONENTS, USED FOR CH. 05, EX. 05 - 10

allocate_array.o: src/allocate_array.cpp src/allocate_array.h
	$(CC) $(CFLAGS) src/allocate_array.cpp
delete_array.o: src/delete_array.cpp src/delete_array.h
	$(CC) $(CFLAGS) src/delete_array.cpp
print_array.o: src/print_array.cpp src/print_array.h
	$(CC) $(CFLAGS) src/print_array.cpp
populate_values.o: src/populate_values.cpp src/populate_values.h
	$(CC) $(CFLAGS) src/populate_array.cpp

multiply.o: src/multiply.cpp src/allocate_array.h src/multiply.h
	$(CC) $(CFLAGS) src/multiply.cpp

determinants.o: src/determinants.cpp src/determinants.h
	$(CC) $(CFLAGS) src/determinants.cpp

# ---------------------------------------------------------------------------- #
# CH. 05, EXERCISE 05

ch05ex05.o: ch05ex05.cpp $(ARRAY_H)
	$(CC) $(CFLAGS) src/ch05ex05.cpp
ch05ex05: ch05ex05.o $(ARRAY_O)
	$(CC) $(LDFLAGS) ch05ex05.o $(ARRAY_O) -o ch05ex05

# ---------------------------------------------------------------------------- #
# CH. 05, EXERCISE 06

ch05ex06.o: ch05ex06.cpp $(ARRAY_H)
	$(CC) $(CFLAGS) src/ch05ex06.cpp
ch05ex06: ch05ex06.o $(ARRAY_O)
	$(CC) $(LDFLAGS) ch05ex06.o $(ARRAY_O) -o ch05ex06

# ---------------------------------------------------------------------------- #
# CH. 05, EXERCISE 07

calculate_p_norm.o: src/calculate_p_norm.cpp src/calculate_p_norm.h
	$(CC) $(CFLAGS) src/calculate_p_norm.cpp
ch05ex07.o: src/ch05ex07.cpp src/calculate_p_norm.h
	$(CC) $(CFLAGS) src/ch05ex07.cpp
ch05ex07: ch05ex07.o calculate_p_norm.o
	$(CC) $(LDFLAGS) ch05ex07.o calculate_p_norm.o -o ch05ex07

# ---------------------------------------------------------------------------- #
# CH. 05, EXERCISE 08

ch05ex08.o: src/ch05ex08.cpp $(ARRAY_H) src/determinants.h
	$(CC) $(CFLAGS) src/ch05ex08.cpp
ch05ex08: ch05ex08.o $(ARRAY_O) determinants.o
	$(CC) $(CFLAGS) ch05ex08.o $(ARRAY_O) determinants.o -o ch05ex08

# ---------------------------------------------------------------------------- #
# CH. 05, EXERCISE 09

CH05EX09_H=src/determinants.h src/lin_solve_3x3.h
CH05EX09_O=$(CH05EX09_H:.h=.o)

ch05ex09.o: src/ch05ex09.cpp $(ARRAY_H) $(CH05EX09_H)
	$(CC) $(CFLAGS) src/ch05ex09.cpp
ch05ex09: ch05ex09.o $(CH05EX09_O)
	$(CC) $(LDFLAGS) ch05ex09.o $(ARRAY_O) $(CH05EX09_O) -o ch05ex09

# ---------------------------------------------------------------------------- #
# CH. 05, EXERCISE 10

CH05EX10_H=src/lin_solve_gauss.h
CH05EX10_O=$(CH05EX10_H:.h=.o)

ch05ex10.o: src/ch05ex10 $(ARRAY_H) $(CH05EX10_H)
	$(CC) $(CFLAGS) src/ch05ex10.cpp
ch05ex10: ch05ex10.o $(CH05EX10_O)
	$(CC) $(CFLAGS) ch05ex10.o $(ARRAY_O) $(CH05EX10_O) -o ch05ex10
