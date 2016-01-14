/*
 * Exercise5-4.cpp
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

#include "calc_mean.h"
#include "calc_sdev.h"
#include <iostream>

int main(int argc, char **argv)
{
	int numLength = 9;
	double *array = new double [numLength];
	array[0] = 0.7983358;
	array[1] = 2.4639492;
	array[2] = 7.4154464;
	array[3] = 8.0242104;
	array[4] = 3.0766765;
	array[5] = 5.2871120;
	array[6] = 0.2433738;
	array[7] = 7.8134121;
	array[8] = 1.0746895;

	for (int i = 0; i < numLength; i++) {
		std::cout << array[i] << "  ";
	}
	std::cout << "\n";
	std::cout << "Mean = " << calc_mean(array, numLength) << "\n";
	std::cout << "Standard deviation = " << calc_sdev(array, numLength) << "\n";

	std::cout << "\n";

	int testLength = 3;
	double *testNums = new double [testLength];
	testNums[0] = 0.0;
	testNums[1] = 5.0;
	testNums[2] = 3.4;

	for (int i = 0; i < 3; i++) {
		std::cout << testNums[i] << "  ";
	}
	std::cout << "\n";
	std::cout << "Mean = " << calc_mean(testNums, testLength) << "\n";
	std::cout << "Standard deviation = " << calc_sdev(testNums, testLength) << "\n";
	
	return 0;
}
