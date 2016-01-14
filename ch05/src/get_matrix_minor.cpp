/*
 * untitled.cxx
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


#include "get_matrix_minor.h"

void get_matrix_minor(int n, int i, int j, double **matrix, double **minor) {
	// Calculates the (ij)th minor of an n x n matrix
	assert(0 <= i && i <= n - 1);
	assert(0 <= j && j <= n - 1);

	for (int p = 0; p < n; p++) {
		for (int q = 0; q < n; q++) {
			if (p < i) {
				if (q < j) {
					minor[p][q] = matrix[p][q];
				} else if (q == j) {
					continue;
				} else {
					minor[p][q - 1] = matrix[p][q];
				}
			} else if (p == i) {
				continue;
			} else {
				if (q < j) {
					minor[p - 1][q] = matrix[p][q];
				} else if (q == j) {
					continue;
				} else {
					minor[p - 1][q - 1] = matrix[p][q];
				}
			}
		}
	}
}
