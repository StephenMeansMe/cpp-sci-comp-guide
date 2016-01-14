/*
 * Exercise5-8
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
#include "determinants.h"
#include "get_matrix_minor.h"

#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
	srand(199004);
	int n_1 = 2;
	int n_2 = 3;
	int n_3 = 4;
	int* dim_A = new int [2];
	int* dim_B = new int [2];
	int* dim_C = new int [2];
	dim_A[0] = n_1; dim_A[1] = n_1;
	dim_B[0] = n_2; dim_B[1] = n_2;
	dim_C[0] = n_3; dim_C[1] = n_3;

	double** mat_A = allocate_array(dim_A);
	double** mat_B = allocate_array(dim_B);
	double** mat_C = allocate_array(dim_C);

	populate_values(mat_A, dim_A);
	populate_values(mat_B, dim_B);
	populate_values(mat_C, dim_C);

	std::cout << "First matrix:\n";
	print(mat_A, dim_A[0], dim_A[1]);
	std::cout << "Determinant (recursive): "
			  << det_n(n_1, mat_A) << "\n"
			  << "Determinant (hard-code): "
			  << det_2(mat_A) << "\n";

	std::cout << "\nSecond matrix:\n";
	print(mat_B, dim_B[0], dim_B[1]);
	std::cout << "Determinant (recursive): "
			  << det_n(n_2, mat_B) << "\n"
			  << "Determinant (hard-code): "
			  << det_3(mat_B) << "\n";

	std::cout << "\nThird matrix:\n";
	print(mat_C, dim_C[0], dim_C[1]);
	std::cout << "Determinant (recursive): "
			  << det_n(n_3, mat_C) << "\n";
	
	delete_array(mat_A, dim_A);
	delete_array(mat_B, dim_B);
	delete_array(mat_C, dim_C);
	delete[] dim_A;
	delete[] dim_B;
	delete[] dim_C;
	
	return 0;
}
