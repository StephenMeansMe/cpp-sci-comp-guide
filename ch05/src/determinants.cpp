/*
 * determinants.cpp
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
#include "delete_array.h"
#include "determinants.h"
#include <cassert>

double det_2(double **m_A) {
	double det = 0.0;
	det = m_A[0][0] * m_A[1][1] - m_A[0][1] * m_A[1][0];
	return det;
}

double det_3(double **m_A) {
	double det = 0.0;
	int *dim = new int [2];
	dim[0] = 2; dim[1] = 2;
	double **minor_1 = allocate_array(dim);
	double **minor_2 = allocate_array(dim);
	double **minor_3 = allocate_array(dim);

	minor_1[0][0] = m_A[1][1]; minor_1[0][1] = m_A[1][2];
	minor_1[1][0] = m_A[2][1]; minor_1[1][1] = m_A[2][2];

	minor_2[0][0] = m_A[1][0]; minor_2[0][1] = m_A[1][2];
	minor_2[1][0] = m_A[2][0]; minor_2[1][1] = m_A[2][2];

	minor_3[0][0] = m_A[1][0]; minor_3[0][1] = m_A[1][1];
	minor_3[1][0] = m_A[2][0]; minor_3[1][1] = m_A[2][1];

	det += m_A[0][0] * det_2(minor_1);
	det -= m_A[0][1] * det_2(minor_2);
	det += m_A[0][2] * det_2(minor_3);

	delete_array(minor_1, dim);
	delete_array(minor_2, dim);
	delete_array(minor_3, dim);

	return det;
}

double det_n(int n, double **m_A)
{
	assert(n > 0);
	double det = 0.0;
	if (n == 1) {
		return m_A[0][0];
	}
		int *dim_matrix = new int[2];
		int *dim_minor  = new int[2];
		int sgn = 1;

		dim_matrix[0] = n;     dim_matrix[1] = n;
		dim_minor[0]  = n - 1; dim_minor[1]  = n - 1;

		double** minor = allocate_array(dim_minor);
	
		for(int i = 0; i < n; i++) {
			get_matrix_minor(n, 0, i, m_A, minor); 
			det += sgn * m_A[0][i] * det_n(n - 1, minor);
			sgn *= -1; // alternate signs
		}

		delete_array(minor, dim_minor); // free up minor of size n-1
	
	return det;
}
