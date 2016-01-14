/*
 * Exercise5-6.cpp
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
#include "print_array.h"
#include "populate_values.h"
#include "multiply.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
	srand(199004);
	
	int *dim_A = new int [2];
	dim_A[0] = 5; dim_A[1] = 3;
	double** A = allocate_array(dim_A[0], dim_A[1]);
	populate_values(A, dim_A[0], dim_A[1]);

	int *dim_B = new int [2];
	dim_B[0] = 3; dim_B[1] = 2;
	double** B = allocate_array(dim_B[0], dim_B[1]);
	populate_values(B, dim_B[0], dim_B[1]);

	print_array(A, dim_A[0], dim_A[1]);
	std::cout << "\n";
	print_array(B, dim_B[0], dim_B[1]);
	std::cout << "\n";

	double** AB = multiply(A, B, dim_A, dim_B);
	print_array(AB, dim_A[0], dim_B[1]);

	delete_array(AB, dim_A[0], dim_B[1]);
	delete_array(A, dim_A[0], dim_A[1]);
	delete[] dim_A;
	delete_array(B, dim_B[0], dim_B[1]);
	delete[] dim_B;
	
	return 0;
}
