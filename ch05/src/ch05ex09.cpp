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

#include <iostream>
#include <cstdlib>

#include "allocate_array.h"
#include "delete_array.h"
#include "lin_solve_3x3.h"
#include "multiply.h"
#include "populate_values.h"
#include "print_array.h"

int main(int argc, char **argv)
{
	int* dim_mat = new int [2];
	dim_mat[0] = 3; dim_mat[1] = 3;
	double** t_A = allocate_array(dim_mat);
	double* t_v = new double [3];

	srand(199004);

	populate_values(t_A, dim_mat);
	populate_values(t_v, 3);

	t_A[0][0] += 0.5;
	t_A[1][1] += 0.5;
	t_A[2][2] += 0.5;

	std::cout << "The matrix is:\n";
	print_array(t_A, dim_mat);
	
	std::cout << "\nThe objective vector is:\n";
	print_array(t_v, 3);

	double* sol_vector = lin_solve_3x3(t_A, t_v);
	std::cout << "\nThe solution vector is:\n";
	print_array(sol_vector, 3);

	std::cout << "\nTesting...\n" 
		  << multiply(t_A, sol_vector, dim_mat, 3) << "\n"; 

	delete_array(t_A, dim_mat);
	delete[] dim_mat;
	delete[] t_v;
	delete[] sol_vector;
	
	return 0;
}
