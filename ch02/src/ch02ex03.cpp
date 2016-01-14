/*
 * Exercise2-1.cpp
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
	 * 
	 */
	int sum_of_integers = 0;
	bool flag = false;
	std::cout << "Integer Sum Calculator. Enter a positive integer to begin.\n"
			  << "Enter -1 to calculate the sum, or -2 to zero out the sum.\n";
	do
	{
		int next_int = 0;
		std::cout << "Enter a positive integer: ";
		std::cin >> next_int;
		if ( !(next_int > 0) )
		{
			if (next_int == -1)
			{
				flag = true; // Break
				std::cout << "Manual termination; stopping... \n";
			}
			else if (next_int == -2)
			{
				sum_of_integers = 0; // Reset sum
				std::cout << "Sum reset to zero! \n";
			}
			else // next_int is 0 or less than -2
			{
				std::cout << "WARNING: Entry not a positive integer.\n";
			}
		}
		else // next_int > 0
		{
			sum_of_integers += next_int;
			if (sum_of_integers > 100)
			{
				flag = true;
				std::cout << "Sum exceeds 100; stopping... \n";
			}
		}
	}
	while (flag != true);
	std::cout << "The sum of these integers is " << sum_of_integers << ".\n";
	return 0;
}
