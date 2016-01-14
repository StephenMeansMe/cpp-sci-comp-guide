/*
 * Exercise2-5.cpp
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

int main(int argc, char **argv)
{
	// Calculate the inverse of a matrix
	double A[2][2] = { {4.0, 10.0}, {1.0, 1.0} };
	double determinant = A[0][0] * A[1][1] - A[0][1] * A[1][0];

	// Check that the determinant is non-zero
	assert(determinant != 0);

	// Calculate the inverse
	double invA[2][2];
	invA[0][0] = A[1][1] / determinant;
	invA[0][1] = -1 * A[0][1] / determinant;
	invA[1][0] = -1 * A[1][0] / determinant;
	invA[1][1] = A[0][0] / determinant;

	// Print the result to console
	std::cout << "The entries of A^-1 are:\n"
			  << invA[0][0] << "\t" << invA[0][1] << "\n"
			  << invA[1][0] << "\t" << invA[1][1] << "\n";
	return 0;
}

