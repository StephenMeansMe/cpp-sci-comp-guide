/*
 * Exercise.cpp
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

int main(int argc, char **argv)
{
	// Newton-Raphson algorithm
	double x_next = 0.0;

	// Initial guess
	double x_prev = 0.0;

	do
	{
		x_prev = x_next;
		x_next = x_prev - (exp(x_prev) + pow(x_prev, 3.0) - 5.0) /
						(exp(x_prev) + 3.0 * pow(x_prev, 2.0));
		std::cout << "Next step: " << x_next << "\n";
		std::cout << "Check: f(x_i) = " << exp(x_next) + pow(x_next, 3.0) - 5 << "\n";
	} while (fabs(x_next - x_prev) > 1e-10);
	return 0;
}
