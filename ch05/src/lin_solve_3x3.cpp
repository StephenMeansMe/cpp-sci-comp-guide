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

#include "allocate_array.h"
#include "determinants.h"
#include "multiply.h"
#include "lin_solve_3x3.h"
#include <iostream>

double** invert_3x3matrix(double** m)
{
	double A, B, C, D, E, F, G, H, I;
	double det = det_3(m);
	int* dim = new int [2];
	dim[0] = 3; dim[1] = 3;
	
	A = m[1][1] * m[2][2] - m[1][2] * m[2][1];
	B = -1 * (m[1][0] * m[2][2] - m[1][2] * m[2][0]);
	C = m[1][0] * m[2][1] - m[1][1] * m[2][0];
	
	D = -1 * (m[0][1] * m[2][2] - m[0][2] * m[2][1]);
	E = m[0][0] * m[2][2] - m[0][2] * m[2][0];
	F = -1 * (m[0][0] * m[2][1] - m[0][1] * m[2][0]);

	G = m[0][1] * m[1][2] - m[0][2] * m[1][1];
	H = -1 * (m[0][0] * m[1][2] - m[0][2] * m[1][0]);
	I = m[0][0] * m[1][1] - m[0][1] * m[1][0];

	double** inverse = allocate_array(dim);
	inverse[0][0] = A; inverse[0][1] = D; inverse[0][2] = G;
	inverse[1][0] = B; inverse[1][1] = E; inverse[1][2] = H;
	inverse[2][0] = C; inverse[2][1] = F; inverse[2][2] = I;

	inverse = multiply(1 / det, inverse, dim);
	delete[] dim;
	return inverse;
}

double* lin_solve_3x3(double** matrix, double* vector) {
	int* dim_mat = new int [2];
	dim_mat[0] = 3; dim_mat[1] = 3;
	double** inverse = invert_3x3matrix(matrix);
	double* solution = multiply(inverse, vector, dim_mat, 3);
	return solution;
}
