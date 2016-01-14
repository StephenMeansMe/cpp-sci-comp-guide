/*
 * Exercise 5-9.cpp
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
#include "populate_values.h"
#include "print_array.h"
#include "lin_solve_3x3.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
	int* dim_mat = new int [2];
	dim_mat[0] = 3; dim_mat[1] = 3;
	double** test_matrix = allocate_array(dim_mat);
	double* test_vector = allocate_array(3);

	srand(199004);

	populate_values(test_matrix, dim_mat);
	populate_values(test_vector, 3);

	test_matrix[0][0] += 0.5;
	test_matrix[1][1] += 0.5;
	test_matrix[2][2] += 0.5;

	std::cout << "The matrix is:\n";
	print_array(test_matrix, dim_mat);
	
	std::cout << "\nThe objective vector is:\n";
	print_array(test_vector, 3);

	double* sol_vector = lin_solve_3x3(test_matrix, test_vector);
	std::cout << "\nThe solution vector is:\n";
	print_array(sol_vector, 3);

	delete_array(test_matrix, dim_mat);
	delete[] dim_mat;
	delete[] test_vector;
	delete[] sol_vector;
	
	return 0;
}
