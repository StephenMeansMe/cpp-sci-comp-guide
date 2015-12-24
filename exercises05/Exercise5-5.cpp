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


#include <iostream>
#include <cstdlib>
#include <cassert>

double** AllocateMatrixMemory(int numRows, int numCols);
void PopulateMatrixValues(double** matrix, int numRows, int numCols);
void PrintMatrix(double** matrix, int numRows, int numCols);
double** Multiply(double **A, double **B, int* dim_A, int* dim_B);

int main(int argc, char **argv)
{
	int *dim_A = new int [2];
	dim_A[0] = 5; dim_A[1] = 3;
	double** A = AllocateMatrixMemory(dim_A[0], dim_A[1]);
	PopulateMatrixValues(A, dim_A[0], dim_A[1]);

	int *dim_B = new int [2];
	dim_B[0] = 3; dim_B[1] = 2;
	double** B = AllocateMatrixMemory(dim_B[0], dim_B[1]);
	PopulateMatrixValues(B, dim_B[0], dim_B[1]);

	PrintMatrix(A, dim_A[0], dim_A[1]);
	std::cout << "\n";
	PrintMatrix(B, dim_B[0], dim_B[1]);
	std::cout << "\n";

	double** AB = Multiply(A, B, dim_A, dim_B);
	PrintMatrix(AB, dim_A[0], dim_B[1]);
	
	return 0;
}

double** AllocateMatrixMemory(int numRows, int numCols)
{
	double** matrix;
	matrix = new double* [numRows];
	for(int i = 0; i < numRows; i++)
	{
		matrix[i] = new double [numCols];
	}
	return matrix;
}

void PopulateMatrixValues(double** matrix, int numRows, int numCols)
{
	srand(199004);
	for(int i = 0; i < numRows; i++)
	{
		for(int j = 0; j < numCols; j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}
}

void PrintMatrix(double** matrix, int numRows, int numCols)
{
	for(int i = 0; i < numRows; i++)
	{
		for(int j = 0; j < numCols; j++)
		{
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << "\n";
	}
}

double** Multiply(double **A, double **B, int *dim_A, int *dim_B)
{
	assert(dim_A[1] == dim_B[0]);
	int numRows = dim_A[0];
	int numCols = dim_B[1];
	int join = dim_A[1];
	
	double **product = AllocateMatrixMemory(numRows, numCols);
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
