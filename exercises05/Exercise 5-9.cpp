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

double** AllocateMatrixMemory(int* dimensions);
double* AllocateVectorMemory(int numEntries);

void DeallocateMatrixMemory(double** matrix, int* dimensions);

void PopulateMatrixValues(double** matrix, int* dimensions);
void PopulateVectorValues(double* vector, int numEntries);

void PrintMatrix(double** matrix, int* dimensions);
void PrintVector(double* vector, int numEntries);

double** Multiply(double x, double** A, int* dim_A); // num * mat
double* Multiply(double** A, double* v, int* dim_A, int length_v); // mat * vec

double CalcDeterminant(int n, double** m_A);
void GetMatrixMinor(int n, int i, int j, double** matrix, double** minor);

double** InvertMatrix(int n, double** matrix);
double* NonSing3x3LinSolve(double** matrix, double** vector);

int main(int argc, char **argv)
{
	
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

double** InvertMatrix(int n, double** matrix)
{
	
}

double* NonSing3x3LinSolve(double** matrix, double** vector)
{
	

}
