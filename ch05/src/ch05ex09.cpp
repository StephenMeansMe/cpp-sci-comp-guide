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
#include <cassert>
#include <cstdlib>

double** AllocateMatrixMemory(int* dimensions);
double* AllocateVectorMemory(int numEntries);

void DeallocateMatrixMemory(double** matrix, int* dimensions);

void PopulateMatrixValues(double** matrix, int* dimensions);
void PopulateVectorValues(double* vector, int numEntries);

void PrintMatrix(double** matrix, int* dimensions);
void PrintVector(double* vector, int numEntries);

double** Multiply(double x, double** A, int* dim_A); // num * mat
double* Multiply(double** A, double* v, int* dim_A, int length_v); // mat * vec

double Calc2x2Det(double** m_A);
double Calc3x3Det(double** m_A);

double** Invert3x3Matrix(int n, double** m);
double* NonSing3x3LinSolve(double** matrix, double* vector);

int main(int argc, char **argv)
{
	int* dim_mat = new int [2];
	dim_mat[0] = 3; dim_mat[1] = 3;
	double** test_matrix = AllocateMatrixMemory(dim_mat);
	double* test_vector = AllocateVectorMemory(3);

	srand(199004);

	PopulateMatrixValues(test_matrix, dim_mat);
	PopulateVectorValues(test_vector, 3);

	test_matrix[0][0] += 0.5;
	test_matrix[1][1] += 0.5;
	test_matrix[2][2] += 0.5;

	std::cout << "The matrix is:\n";
	PrintMatrix(test_matrix, dim_mat);
	
	std::cout << "\nThe objective vector is:\n";
	PrintVector(test_vector, 3);

	double* sol_vector = NonSing3x3LinSolve(test_matrix, test_vector);
	std::cout << "\nThe solution vector is:\n";
	PrintVector(sol_vector, 3);

	DeallocateMatrixMemory(test_matrix, dim_mat);
	delete[] dim_mat;
	delete[] test_vector;
	delete[] sol_vector;
	
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
	//srand(199004);
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
	//srand(199004);
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

double** Multiply(double x, double** A, int* dim_A) // num * mat
{
	double** product_xA = AllocateMatrixMemory(dim_A);
	
	for (int i = 0; i < dim_A[0]; i++)
	{
		for (int j = 0; j < dim_A[1]; j++)
		{
			product_xA[i][j] = x * A[i][j];
		}
	}
	return product_xA;	
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

double Calc2x2Det(double** m_A)
{
	double det = 0.0;
	det = m_A[0][0] * m_A[1][1] - m_A[0][1] * m_A[1][0];
	return det;
}

double Calc3x3Det(double** m_A)
{
	double det = 0.0;
	int* dim = new int [2];
	dim[0] = 2; dim[1] = 2;
	double** minor_1 = AllocateMatrixMemory(dim);
	double** minor_2 = AllocateMatrixMemory(dim);
	double** minor_3 = AllocateMatrixMemory(dim);

	minor_1[0][0] = m_A[1][1]; minor_1[0][1] = m_A[1][2];
	minor_1[1][0] = m_A[2][1]; minor_1[1][1] = m_A[2][2];

	minor_2[0][0] = m_A[1][0]; minor_2[0][1] = m_A[1][2];
	minor_2[1][0] = m_A[2][0]; minor_2[1][1] = m_A[2][2];

	minor_3[0][0] = m_A[1][0]; minor_3[0][1] = m_A[1][1];
	minor_3[1][0] = m_A[2][0]; minor_3[1][1] = m_A[2][1];

	det += m_A[0][0] * Calc2x2Det(minor_1);
	det -= m_A[0][1] * Calc2x2Det(minor_2);
	det += m_A[0][2] * Calc2x2Det(minor_3);

	DeallocateMatrixMemory(minor_1, dim);
	DeallocateMatrixMemory(minor_2, dim);
	DeallocateMatrixMemory(minor_3, dim);

	return det;
}

double** Invert3x3Matrix(double** m)
{
	double A, B, C, D, E, F, G, H, I;
	double det = Calc3x3Det(m);
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

	double** inverse = AllocateMatrixMemory(dim);
	inverse[0][0] = A; inverse[0][1] = D; inverse[0][2] = G;
	inverse[1][0] = B; inverse[1][1] = E; inverse[1][2] = H;
	inverse[2][0] = C; inverse[2][1] = F; inverse[2][2] = I;

	inverse = Multiply(1 / det, inverse, dim);
	delete[] dim;
	return inverse;
}

double* NonSing3x3LinSolve(double** matrix, double* vector)
{
	int* dim_mat = new int [2];
	dim_mat[0] = 3; dim_mat[1] = 3;
	double** inverse = Invert3x3Matrix(matrix);
	double* solution = Multiply(inverse, vector, dim_mat, 3);
	return solution;
}
