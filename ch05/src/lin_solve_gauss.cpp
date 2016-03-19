/*
 * lin_solve_gauss.cpp
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

#include "lin_solve_gauss.h"
#include <iostream>

double* lin_solve_gauss(double** A, double* b, int n) {
	for (int i = 0; i < n; i++) {
		// Pivot at each step; search for largest abs(a_ki, k = i, i+1,..., n-1)
		int rowWithBiggest = i;
		for (int j = i; j < n; j++) {
			if (fabs(A[j][i]) > fabs(A[i][i])) {
				rowWithBiggest = j;
			}
		}
		if (rowWithBiggest != i) {
			pivot_rows(A, i, rowWithBiggest, n);
			double swap = b[i];
			b[i] = b[rowWithBiggest];
			b[rowWithBiggest] = swap;
		}
		// Now construct A^(k)
		for (int r = i+1; r < n; r++) {
			double m = A[r][i] / A[i][i];
			A[r][i] = 0.0; // Zeros out this column by definition
			b[r] = b[r] - m * b[i]; // Adjusts the objective vector
			for (int r_2 = r; r_2 < n; r_2++) {
				for (int c = i+1; c < n; c++) {
					A[r_2][c] = A[r_2][c] - m * A[i][c];
				}
			}
		}
	} // We should now have an upper-triangular matrix

	back_solve(A, b, n); // Back-solve, replacing the entries of vector b
	return b;
}

void pivot_rows(double** A, int row1, int row2, int n) {
	if (((row1 < n) and (row1 < n)) and ((row2 > 0) and (row2 < n))) {
		double *swap = A[row1];
		A[row1] = A[row2];
		A[row2] = swap;
	} else {
		std::cerr << "Warning: row entry/entries out of bounds! \n";
	}
}

void back_solve(double** T, double* x, int n) {
	x[n-1] = T[n-1][n-1] / x[n-1];
	double s = T[n-2][n-1] * x[n-1];
	x[n-2] = (x[n-2] - s) / T[n-2][n-2];
	if (n > 2) {
		for (int k = n - 3; k > 0; k--) {
			s = s + T[k][k+1] * x[k+1];
			x[k] = (x[k] - s) / T[k][k];
		}
	}
}
