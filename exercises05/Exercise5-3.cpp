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


#include <iostream>

void swapVars(double *var); // with pointers

void swapVars(double &var1, double &var2); // with references

int main(int argc, char **argv)
{
	double *x = new double;
	x[1] = 0.2, x[2] = -9.1;
	
	std::cout << "1st pair of variables: " << x[1] << ", " << x[2] << ";\n";
	swapVars(x); // swap variables by pointers
	std::cout << "1st pair, swapped: "     << x[1] << ", " << x[2] << ".\n";
	delete[] x;

	std::cout << "\n";
	
    double *y = new double;
	y[1] = 1.7, y[2] = -5.4;

	std::cout << "2nd pair of variables: " << y[1] << " " << y[2] << ";\n";
	swapVars(y[1], y[2]); // swap variables by references
	std::cout << "2nd pair, swapped: "     << y[1] << " " << y[2] << ".\n";
	
	return 0;
}

void swapVars(double *var)
{
	std::cout << "Swapping with pointers!\n";
	double *swap = new double;
	*swap = var[2];
	var[2] = var[1];
	var[1] = *swap;
	delete swap;
}

void swapVars(double &var1, double &var2)
{
	std::cout << "Swapping with references!\n";
	double *swap = new double;
	*swap = var2;
	var2 = var1;
	var1 = *swap;
	delete swap;	
}
