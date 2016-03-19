/*
 * ch06ex01_7.cpp
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

#include "ComplexMatrix.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv)
{
	/*
	 * Testing the matrix exponential function
	 */

	// Create new 3x3 matrix of complex numbers
	ComplexNumber** cmat = AllocateComplexMatrix();
	
	cmat[0][0] = ComplexNumber(rand(), rand());
	cmat[0][1] = ComplexNumber(rand(), rand());
	cmat[0][2] = ComplexNumber(rand(), rand());
	
	cmat[1][0] = ComplexNumber(rand(), rand());
	cmat[1][1] = ComplexNumber(rand(), rand());
	cmat[1][2] = ComplexNumber(rand(), rand());

	cmat[2][0] = ComplexNumber(rand(), rand());
	cmat[2][1] = ComplexNumber(rand(), rand());
	cmat[2][2] = ComplexNumber(rand(), rand());
	
	
	return 0;
}

