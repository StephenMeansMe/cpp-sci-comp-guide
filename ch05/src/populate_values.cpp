/*
 * populate_values.cpp
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

#include "populate_values.h"
#include <cstdlib>

void populate_values(double** matrix, int numRows, int numCols)
{
	for(int i = 0; i < numRows; i++)
	{
		for(int j = 0; j < numCols; j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}
}

void populate_values(double** matrix, int* dimensions)
{
	populate_values(matrix, dimensions[0], dimensions[1])
}

void populate_values(double* vector, int numEntries)
{
	for(int i = 0; i < numEntries; i++)
	{
		vector[i] = rand() % 10;
	}
}
