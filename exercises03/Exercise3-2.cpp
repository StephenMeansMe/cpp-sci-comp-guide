/*
 * Exercise3-2.cpp
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

int main(int argc, char **argv)
{
	std::ifstream read_file("x_and_y.dat");
	if (!read_file.is_open())
	{
		return 1;
	}
	int number_of_rows = 0;
	while (!read_file.eof())
	{
		double dummy1, dummy2, dummy3, dummy4;
		read_file >> dummy1 >> dummy2;
		read_file >> dummy3 >> dummy4;
		if (!read_file.fail())
		{
			number_of_rows++;
		}
	}
	std::cout << "Number of rows: " << number_of_rows << "\n";
	read_file.close();

	return 0;
}
