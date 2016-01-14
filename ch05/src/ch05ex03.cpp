/*
 * Exercise5-3.cpp
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

#include "swap_vars.h"
#include <iostream>

int main(int argc, char **argv)
{
	double *x = new double;
	x[1] = 0.2, x[2] = -9.1;
	
	std::cout << "1st pair of variables: " << x[1] << ", " << x[2] << ";\n";
	std::cout << "Swapping with pointers!\n"; swap_vars(x);
	std::cout << "1st pair, swapped: "     << x[1] << ", " << x[2] << ".\n";
	delete[] x;

	std::cout << "\n";
	
    double *y = new double;
	y[1] = 1.7, y[2] = -5.4;

	std::cout << "2nd pair of variables: " << y[1] << " " << y[2] << ";\n";
	std::cout << "Swapping with references!\n"; swap_vars(y[1], y[2]);
	std::cout << "2nd pair, swapped: "     << y[1] << " " << y[2] << ".\n";
	delete[] y;
	
	return 0;
}
