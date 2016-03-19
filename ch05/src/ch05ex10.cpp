/*
 * Exercise5-10.cpp
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

#include "allocate_array.h"
#include "delete_array.h"
#include "lin_solve_gauss.h"
#include "multiply.h"
#include "print_array.h"

int main(int argc, char **argv)
{
	int n = 3;
	double* tb = new double [3];
	tb[0] = 3.0; tb[1] = -1.0; tb[2] = -0.025; 
	
	int* dim_tA = new int [2];
	dim_tA[0] = 3;
	dim_tA[1] = 3;
	double** tA = allocate_array(dim_tA);
	tA[0][0] = 1.0; tA[0][1] = 0.0; tA[0][2] = 0.0;
	tA[1][0] = 0.0; tA[1][1] = 1.0; tA[1][2] = 0.0;
	tA[2][0] = 0.0; tA[2][1] = 0.0; tA[2][2] = 1.0;

	double* tx = new double [3];
	tx = lin_solve_gauss(tA, tb, n);

	print_array(tA, dim_tA);
	print_array(tb, 3);
	print_array(tx, 3);

	delete_array(tA, dim_tA);
	delete[] tb;
	delete[] tx;
	return 0;
}
