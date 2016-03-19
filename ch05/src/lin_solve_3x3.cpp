/*
 * lin_solve_3x3.cpp
 * 
 * Copyright 2016 Stephen <me@stephenmeansme.com>
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

#include "lin_solve_3x3.h"

#include <iostream>

#include "allocate_array.h"
#include "determinants.h"
#include "multiply.h"

double** invert_3x3matrix(double** m, int* dim) {

	if ((dim[0] < 3) or (dim[1] < 3)) {
		std::cerr << "Error: Dimensions less than 3";
	} else if (dim[0] != dim[1]) {
		std::cerr << "Error: Dimensions not equal";
	} else {
		if ((dim[0] > 3) or (dim[1] > 3)) {
			std::cerr << "Warning: Dimensions greater than 3; pruning...";
			dim[0] = 3;
			dim[1] = 3;
		} else { // dim[0] = 3 and dim[1] = 3
	
			double det = det_3(m);
	
			double A = m[1][1] * m[2][2] - m[1][2] * m[2][1];
			double B = -1 * (m[1][0] * m[2][2] - m[1][2] * m[2][0]);
			double C = m[1][0] * m[2][1] - m[1][1] * m[2][0];
	
			double D = -1 * (m[0][1] * m[2][2] - m[0][2] * m[2][1]);
			double E = m[0][0] * m[2][2] - m[0][2] * m[2][0];
			double F = -1 * (m[0][0] * m[2][1] - m[0][1] * m[2][0]);

			double G = m[0][1] * m[1][2] - m[0][2] * m[1][1];
			double H = -1 * (m[0][0] * m[1][2] - m[0][2] * m[1][0]);
			double I = m[0][0] * m[1][1] - m[0][1] * m[1][0];

			m[0][0] = A; m[0][1] = D; m[0][2] = G;
			m[1][0] = B; inverse[1][1] = E; inverse[1][2] = H;
			m[2][0] = C; inverse[2][1] = F; inverse[2][2] = I;

			m = multiply(1 / det, m, dim);
		}
	}
}

double* lin_solve_3x3(double** matrix, double* vector) {
	int* dim_mat = new int [2];
	dim_mat[0] = 3; dim_mat[1] = 3;
	double** inverse = invert_3x3matrix(matrix);
	double* solution = multiply(inverse, vector, dim_mat, 3);
	return solution;
}
