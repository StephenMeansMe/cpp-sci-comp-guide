/*
 * Exercise4-3.cpp
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

#include <cstdlib>
#include <iostream>

int main(int argc, char **argv)
{
	std::srand(333); // Set random seed

	int *p_x, *p_y;
	int loop_times = 1e+9; // Loop 1,000,000,000 times
	
	for (int i = 0; i < loop_times; i++)
	{
		// Dynamic allocation of vectors
		p_x = new int [3];
		p_y = new int [3];

		// Random seeding of vectors
		for (int j = 0; j < 3; j++)
		{
			p_x[j] = std::rand();
			p_y[j] = std::rand();
		}

		// De-allocation of vectors
		delete p_x;
		delete p_y;
	}

	return 0;
}

