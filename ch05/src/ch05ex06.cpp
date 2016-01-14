/*
 * Exercise5-7.cpp
 * 
 * Copyright 2015 Stephen <me@stephenmeansme.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "allocate_array.h"
#include "delete_array.h"
#include "multiply.h"
#include "populate_values.h"
#include "print_array.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
	srand(199004);
	
	double test_x = 7.0;
	std::cout << "Test scalar: " << test_x << "\n \n";
	
	int len_v = 6;
	double* test_v = AllocateVectorMemory(len_v);
	populate_values(test_v, len_v);
	std::cout << "Test vector: \n";
	print_array(test_v, len_v); std::cout << "\n";

	int* dim_A = new int [2];
	dim_A[0] = 6; dim_A[1] = 6;
	double** test_A = allocate_array(dim_A);
	populate_values(test_A, dim_A);
	std::cout << "Test matrix: \n";
	print(test_A, dim_A); std::cout << "\n";

	double** xA = multiply(test_x, test_A, dim_A);
	double** Ax = multiply(test_A, test_x, dim_A);

	double* vA = multiply(test_v, test_A, len_v, dim_A);
	double* Av = multiply(test_A, test_v, dim_A, len_v);

	std::cout << "x * A = \n";
	print(xA, dim_A); std::cout << "\n";
	Deallocate_array(xA, dim_A);
	
	std::cout << "A * x = \n";
	print(Ax, dim_A); std::cout << "\n";
	Deallocate_array(Ax, dim_A);

	std::cout << "v * A = \n";
	print(vA, len_v); std::cout << "\n";
	delete[] vA;

	std::cout << "A * v = \n";
	print(Av, len_v); std::cout << "\n";
	delete[] Av;
	
	// Deallocate memory
	delete[] test_v;
	delete_array(test_A, dim_A);
	delete[] dim_A;
	
	return 0;
}
