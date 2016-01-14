/*
 * Exercise2-4.cpp
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

int main(int argc, char **argv)
{
	/*
	 * Exercise 2.4 More matrix operations
	 */
	double u[3] = {1.0, 2.0, 3.0};
	double v[3] = {6.0, 5.0, 4.0};
	double A[3][3] = { {1.0, 5.0, 0.0},
					   {7.0, 1.0, 2.0},
					   {0.0, 0.0, 1.0} };
	double B[3][3] = { {-2.0, 0.0, 1.0},
					   {1.0, 0.0, 0.0},
					   {4.0, 1.0, 0.0} };
	double w[3];
	for (int i = 0; i < 3; i++)
	{
		w[i] = u[i] - 3.0 * v[i];
	}
	std::cout << "The vector w = u - 3v is:\n"
			  << w[0] << "\t" << w[1] << "\t" << w[2] << "\n";

	double x[3] = {0.0, 0.0, 0.0};
	for (int i = 0; i < 3; i++)
	{
		x[i] = u[i] - v[i];
	}
	std::cout << "The vector x = u - v is:\n"
			  << x[0] << "\t" << x[1] << "\t" << x[2] << "\n";

	double y[3] = {0.0, 0.0, 0.0};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			y[i] += A[i][j] * u[j];
		}
	}
	std::cout << "The vector y = Au is:\n"
			  << y[0] << "\t" << y[1] << "\t" << y[2] << "\n";

	double z[3];
	for (int i = 0; i < 3; i++)
	{
		z[i] = y[i] - v[i];
	}
	std::cout << "The vector z = Au - v is:\n"
			  << z[0] << "\t" << z[1] << "\t" << z[2] << "\n";

	double C[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			C[i][j] = 4.0 * A[i][j] - 3.0 * B[i][j];
		}
	}
	std::cout << "The entries of C = 4A - 3B are:\n"
			  << C[0][0] << "\t" << C[0][1] << "\t" << C[0][2] << "\n"
			  << C[1][0] << "\t" << C[1][1] << "\t" << C[1][2] << "\n"
			  << C[2][0] << "\t" << C[2][1] << "\t" << C[2][2] << "\n";

	double D[3][3] = { {0.0, 0.0, 0.0},
					   {0.0, 0.0, 0.0},
					   {0.0, 0.0, 0.0} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				D[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	std::cout << "The entries of D = A * B are:\n"
			  << D[0][0] << "\t" << D[0][1] << "\t" << D[0][2] << "\n"
			  << D[1][0] << "\t" << D[1][1] << "\t" << D[1][2] << "\n"
			  << D[2][0] << "\t" << D[2][1] << "\t" << D[2][2] << "\n";
	return 0;
}
