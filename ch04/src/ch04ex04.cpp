/*
 * Exercise4-4.cpp
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

int main(int argc, char **argv)
{
	std::srand(44);
	int rows = 2, cols = 2;
	int loop_times = 1e+7;
	double **A, **B, **C;
	for (int i = 0; i < loop_times; i++)
	{
		A = new double* [rows];
		B = new double* [rows];
		C = new double* [rows];

		for (int j = 0; j < rows; j++)
		{
			A[j] = new double [cols];
			B[j] = new double [cols];
			C[j] = new double [cols];
		}

		for (int row_i = 0; row_i < rows; row_i++)
		{
			for (int col_j = 0; col_j < cols; col_j++)
			{
				A[row_i][col_j] = std::rand();
				B[row_i][col_j] = std::rand();
				C[row_i][col_j] = A[row_i][col_j] + B[row_i][col_j];
			}
		}

		for (int j = 0; j < rows; j++)
		{
			delete A[j];
			delete B[j];
			delete C[j];
		}
		delete[] A;
		delete[] B;
		delete[] C;
	}
	return 0;
}

