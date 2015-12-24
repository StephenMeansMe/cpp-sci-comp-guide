/*
 * Exercise5-7.cpp
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
#include <cassert>
#include <cstdlib>

double** AllocateMatrixMemory(int* dimensions);
double* AllocateVectorMemory(int numEntries);

void DeallocateMatrixMemory(double** matrix, int* dimensions);

void PopulateMatrixValues(double** matrix, int* dimensions);
void PopulateVectorValues(double* vector, int numEntries);

void PrintMatrix(double** matrix, int* dimensions);
void PrintVector(double* vector, int numEntries);

double** Multiply(double** A, double** B, int* dim_A, int* dim_B);

double** Multiply(double** A, double x, int* dim_A); // mat * num
double** Multiply(double x, double** A, int* dim_A); // num * mat

double* Multiply(double** A, double* v, int* dim_A, int length_v); // mat * vec
double* Multiply(double* v, double** A, int length_v, int* dim_A); // vec * mat

int main(int argc, char **argv)
{
	double test_x = 7.0;
	std::cout << "Test scalar: " << test_x << "\n \n";
	
	int len_v = 6;
	double* test_v = AllocateVectorMemory(len_v);
	PopulateVectorValues(test_v, len_v);
	std::cout << "Test vector: \n";
	PrintVector(test_v, len_v); std::cout << "\n";

	int* dim_A = new int [2];
	dim_A[0] = 6; dim_A[1] = 6;
	double** test_A = AllocateMatrixMemory(dim_A);
	PopulateMatrixValues(test_A, dim_A);
	std::cout << "Test matrix: \n";
	PrintMatrix(test_A, dim_A); std::cout << "\n";

	double** xA = Multiply(test_x, test_A, dim_A);
	double** Ax = Multiply(test_A, test_x, dim_A);

	double* vA = Multiply(test_v, test_A, len_v, dim_A);
	double* Av = Multiply(test_A, test_v, dim_A, len_v);

	std::cout << "x * A = \n";
	PrintMatrix(xA, dim_A); std::cout << "\n";
	DeallocateMatrixMemory(xA, dim_A);
	
	std::cout << "A * x = \n";
	PrintMatrix(Ax, dim_A); std::cout << "\n";
	DeallocateMatrixMemory(Ax, dim_A);

	std::cout << "v * A = \n";
	PrintVector(vA, len_v); std::cout << "\n";
	delete[] vA;

	std::cout << "A * v = \n";
	PrintVector(Av, len_v); std::cout << "\n";
	delete[] Av;
	
	// Deallocate memory
	delete[] test_v;
	DeallocateMatrixMemory(test_A, dim_A);
	delete[] dim_A;
	
	return 0;
}

double** AllocateMatrixMemory(int* dimensions)
{
	double** matrix;
	int numRows = dimensions[0];
	int numCols = dimensions[1];
	matrix = new double* [numRows];
	for(int i = 0; i < dimensions[0]; i++)
	{
		matrix[i] = new double [numCols];
	}
	return matrix;
}

double* AllocateVectorMemory(int numEntries)
{
	double *vector;
	vector = new double [numEntries];
	return vector;
}

void DeallocateMatrixMemory(double** matrix, int* dimensions)
{
	for (int i = 0; i < dimensions[0]; i++)
	{
		delete[] matrix[i];
	}
}

void PopulateMatrixValues(double** matrix, int* dimensions)
{
	srand(199004);
	for(int i = 0; i < dimensions[0]; i++)
	{
		for(int j = 0; j < dimensions[1]; j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}
}

void PopulateVectorValues(double* vector, int numEntries)
{
	srand(199004);
	for(int i = 0; i < numEntries; i++)
	{
		vector[i] = rand() % 10;
	}
}

void PrintMatrix(double** matrix, int* dimensions)
{
	for(int i = 0; i < dimensions[0]; i++)
	{
		for(int j = 0; j < dimensions[1]; j++)
		{
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << "\n";
	}
}

void PrintVector(double* vector, int numEntries)
{
	for (int i = 0; i < numEntries; i++)
	{
		std::cout << vector[i] << "  ";
	}
	std::cout << "\n";
}

double** Multiply(double** A, double** B, int* dim_A, int* dim_B)
{
	assert(dim_A[1] == dim_B[0]);
	int* dimensions = new int [2];
	dimensions[0] = dim_A[0];
	dimensions[1] = dim_B[1];
	int join = dim_A[1];
	
	double** product = AllocateMatrixMemory(dimensions);
	for(int i = 0; i < dimensions[0]; i++)
	{
		for(int j = 0; j < dimensions[1]; j++)
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

double** Multiply(double** A, double x, int* dim_A) // mat * num
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

double** Multiply(double x, double** A, int* dim_A) // num * mat
{
	return Multiply(A, x, dim_A); // symmetry
}

double* Multiply(double** A, double* v, int* dim_A, int length_v) // mat * vec
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

double* Multiply(double* v, double** A, int length_v, int* dim_A) // vec * mat
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
