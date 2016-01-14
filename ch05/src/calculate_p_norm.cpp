/*
 * calculate_p_norm.cpp
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


#include <cmath>

double calculate_p_norm(int size, double* v, int p) {
	double norm = 0.0;
	double elem = 0.0;
	for (int i = 0; i < size; i++) {
		elem = std::abs(v[i]);
		norm += pow(elem, (double)p);
	}
	norm = pow(norm, 1.0 / (double)p);
	return norm;
}
