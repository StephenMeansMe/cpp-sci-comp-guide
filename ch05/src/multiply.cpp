/*
 * multiply.cpp
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


#include "multiply.h"
#include "allocate_memory.h"
#include <cassert>

double** multiply(double **A, double **B, int *dim_A, int *dim_B)
{
	assert(dim_A[1] == dim_B[0]);
	int numRows = dim_A[0];
	int numCols = dim_B[1];
	int join = dim_A[1];
	
	double **product = allocate_array(numRows, numCols);
	for(int i = 0; i < numRows; i++)
	{
		for(int j = 0; j < numCols; j++)
		{
			// AB(i,j) is the scalar product of A(i,:) and B(:,j)
			product[i][j] = 0.0;
			for(int k = 0; k < join; k++)
			{
				product[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return product;
}

double** multiply(double** A, double x, int* dim_A) // mat * num
{
	double** product_Ax = AllocateMatrixMemory(dim_A);
	
	for (int i = 0; i < dim_A[0]; i++)
	{
		for (int j = 0; j < dim_A[1]; j++)
		{
			product_Ax[i][j] = x * A[i][j];
		}
	}
	return product_Ax;	
}

double** multiply(double x, double** A, int* dim_A) // num * mat
{
	return Multiply(A, x, dim_A); // symmetry
}

double* multiply(double** A, double* v, int* dim_A, int length_v) // mat * vec
{
	assert(dim_A[1] == length_v); // must match m x n to n x 1
	double* product_Av = AllocateVectorMemory(dim_A[0]); // A is m x n, Av is m x 1
	for (int i = 0; i < dim_A[0]; i++)
	{
		product_Av[i] = 0.0;
		for (int j = 0; j < dim_A[1]; j++)
		{
			product_Av[i] += A[i][j] * v[j];
		}
	}
	return product_Av;
}

double* multiply(double* v, double** A, int length_v, int* dim_A) // vec * mat
{
	assert(dim_A[0] == length_v); // must match 1 x m to m x n  
	double* product_vA = AllocateVectorMemory(dim_A[1]); // A is m x n, vA is 1 x n
	for (int j = 0; j < dim_A[1]; j++)
	{
		product_vA[j] = 0.0;
		for (int i = 0; i < dim_A[0]; i++)
		{
			product_vA[j] += v[i] * A[i][j];
		}
	}
	return product_vA;
}
