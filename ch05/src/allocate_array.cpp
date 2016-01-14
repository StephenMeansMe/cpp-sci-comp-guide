/*
 * allocate_matrix_memory.cpp
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

double** allocate_array(int numRows, int numCols) {
	double** matrix;
	matrix = new double* [numRows];
	for (int i = 0; i < numRows; i++) {
		matrix[i] = new double [numCols];
	}
	return matrix;
}

double** allocate_array(int* dimensions) {
	return allocate_array(dimensions[0], dimensions[1]);
}
