/*
 * Exercise3-3.cpp
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

#include <fstream>
#include <iostream>
#include <cassert>
#include <cstdlib>

int main(int argc, char **argv)
{
	assert(atoi(argv[1]) > 1);
	int N = atoi(argv[1]);
	std::ofstream write_output("xy.dat");
	assert(write_output.is_open());

	double h = 1 / ((double) N);
	double x_coord = 0.0;
	double y_prev = 1.0;
	double y_next = 1.0;
	write_output << x_coord << "\t" << y_next << "\n";

	for (int i = 1; i < N; i++)
	{
		x_coord = ((double) i) * h;
		y_next = y_prev / (1 + h);
		write_output << x_coord << "\t" << y_next << "\n";
		y_prev = y_next;
	}
	write_output.close();
	
	return 0;
}
