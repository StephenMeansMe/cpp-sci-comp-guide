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


#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>

double** AllocateMatrixMemory(int* dimensions);
void DeallocateMatrixMemory(double** matrix, int* dimensions);

void PopulateMatrixValues(double** matrix, int* dimensions);
void PrintMatrix(double** matrix, int numRows, int numCols);

double Calc2x2Det(double** m_A);
double Calc3x3Det(double** m_A);
double CalcDeterminant(int n, double** m_A);
void GetMatrixMinor(int n, int i, int j, double** matrix, double** minor);

int main(int argc, char **argv)
{
	int n_1 = 2;
	int n_2 = 3;
	int n_3 = 4;
	int* dim_A = new int [2];
	int* dim_B = new int [2];
	int* dim_C = new int [2];
	dim_A[0] = n_1; dim_A[1] = n_1;
	dim_B[0] = n_2; dim_B[1] = n_2;
	dim_C[0] = n_3; dim_C[1] = n_3;

	double** mat_A = AllocateMatrixMemory(dim_A);
	double** mat_B = AllocateMatrixMemory(dim_B);
	double** mat_C = AllocateMatrixMemory(dim_C);

	PopulateMatrixValues(mat_A, dim_A);
	PopulateMatrixValues(mat_B, dim_B);
	PopulateMatrixValues(mat_C, dim_C);

	std::cout << "First matrix:\n";
	PrintMatrix(mat_A, dim_A[0], dim_A[1]);
	std::cout << "Determinant (recursive): "
			  << CalcDeterminant(n_1, mat_A) << "\n"
			  << "Determinant (hard-code): "
			  << Calc2x2Det(mat_A) << "\n";

	std::cout << "\nSecond matrix:\n";
	PrintMatrix(mat_B, dim_B[0], dim_B[1]);
	std::cout << "Determinant (recursive): "
			  << CalcDeterminant(n_2, mat_B) << "\n"
			  << "Determinant (hard-code): "
			  << Calc3x3Det(mat_B) << "\n";

	std::cout << "\nThird matrix:\n";
	PrintMatrix(mat_C, dim_C[0], dim_C[1]);
	std::cout << "Determinant (recursive): "
			  << CalcDeterminant(n_3, mat_C) << "\n";
	
	DeallocateMatrixMemory(mat_A, dim_A);
	DeallocateMatrixMemory(mat_B, dim_B);
	DeallocateMatrixMemory(mat_C, dim_C);
	delete[] dim_A;
	delete[] dim_B;
	delete[] dim_C;
	
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

double CalcDeterminant(int n, double** m_A)
{
	assert(n > 0);
	double det = 0.0;
	if (n == 1) {
		return m_A[0][0];
	}
		int* dim_matrix = new int[2];
		int* dim_minor  = new int[2];
		int sgn = 1;

		dim_matrix[0] = n;   dim_matrix[1] = n;
		dim_minor[0]  = n-1; dim_minor[1]  = n-1;

		double** minor = AllocateMatrixMemory(dim_minor);
	
		for(int i = 0; i < n; i++)
		{
			GetMatrixMinor(n, 0, i, m_A, minor); 
			det += sgn * m_A[0][i] * CalcDeterminant(n-1, minor);
			sgn *= -1; // alternate signs
		}

		DeallocateMatrixMemory(minor, dim_minor); // free up minor of size n-1
	
	return det;
}

void GetMatrixMinor(int n, int i, int j, double** matrix, double** minor)
{
	// Calculates the (ij)th minor of an n x n matrix
	assert(0 <= i && i <= n - 1);
	assert(0 <= j && j <= n - 1);

	for (int p = 0; p < n; p++) {
		for (int q = 0; q < n; q++) {
			if (p < i) {
				if (q < j) {
					minor[p][q] = matrix[p][q];
				} else if (q == j) {
					continue;
				} else {
					minor[p][q - 1] = matrix[p][q];
				}
			} else if (p == i) {
				continue;
			} else {
				if (q < j) {
					minor[p - 1][q] = matrix[p][q];
				} else if (q == j) {
					continue;
				} else {
					minor[p - 1][q - 1] = matrix[p][q];
				}
			}
		}
	}
}
