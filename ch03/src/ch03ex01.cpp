/*
 * Exercise3-1.cpp
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
#include <fstream>
#include <cassert>

int main(int argc, char **argv)
{
	double x[4] = {0.0, 1.0, 1.0, 0.0};
	double y[4] = {0.0, 0.0, 1.0, 1.0};

	// Initialize output file
	std::ofstream write_output("x_and_y.dat");
	assert(write_output.is_open());
	write_output.setf(std::ios::scientific);
	write_output.setf(std::ios::showpos);
	write_output.precision(10);

	// Print vector X to file
	for (int i = 0; i < 4; i++)
	{
		write_output << x[i] << "\t";
	}
	write_output << "\n";
	write_output.flush();

	// Print vector Y to file
	for (int i = 0; i < 4; i++)
	{
		write_output << y[i] << "\t";
	}
	write_output << "\n";
	write_output.flush();

	write_output.close();

	return 0;
}

