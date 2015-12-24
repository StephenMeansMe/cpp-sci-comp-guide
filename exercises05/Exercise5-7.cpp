/*
 * Exercise5-7.cpp
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
#include <cmath>

double CalculatePNorm(int size, double* v, int p = 2);

int main(int argc, char** argv)
{
	int n = 3;
	double* x = new double [n];
	
	x[0] = 1.0; x[1] = 4.0; x[2] = -7.0;

	for(int i = 1; i < 4; i++)
	{
		double vecpnorm = CalculatePNorm(n, x, i);
		std::cout << "Scalar product = "
				<< vecpnorm << "\n";
	}
	delete[] x;
	return 0;
}

double CalculatePNorm(int size, double* v, int p)
{
	double norm = 0.0;
	double elem = 0.0;
	for (int i = 0; i < size; i++)
	{
		elem = std::abs(v[i]);
		norm += pow(elem, (double)p);
	}
	norm = pow(norm, 1.0 / (double)p);
	return norm;
}
