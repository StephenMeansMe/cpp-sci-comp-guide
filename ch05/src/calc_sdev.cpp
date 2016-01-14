/*
 * calc_sdev.cpp
 * 
 * Copyright 2016 Stephen <me@stephenmeansme.com>
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


#include "calc_sdev.h"
#include "calc_mean.h"
#include <iostream>
#include <cmath>

double calc_sdev(double* nums, int numLength) {
	double std_dev;
	
	if (numLength > 1) {
		double xbar = calc_mean(nums, numLength);
		double sum = 0.0;

		for (int i = 0; i < numLength; i++) {
			sum += (nums[i] - xbar) * (nums[i] - xbar);
		}
		double var = sum / (numLength - 1.0);
		std_dev = sqrt(var);
	} else if (numLength == 1) {
		// A single data point has no variance
		std_dev = 0.0;
	} else {
		// Zero or negative (???) length throws a warning and defaults to 0 variance
		std:cerr << "Warning: Length should be a positive integer; setting variance to zero."
		std_dev = 0.0;
	}
	
	return std_dev;
}
