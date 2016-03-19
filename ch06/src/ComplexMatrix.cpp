/*
 * ComplexMatrix.cpp
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

ComplexNumber** AllocateComplexMatrix() {
	int r = 3;
	int c = 3;

	ComplexNumber** cmat = new ComplexNumber* [r];
	for( int i = 0; i < r; i++ ) {
		cmat[i] = new ComplexNumber [c];
	}
	return cmat;
}

void CalculateMatrixExp( long N, ComplexNumber** cmat ) {
	int r = 3;
	int c = 3;

	for( int n = 0; n < N; n++ ) {
		//
		ComplexNumber** nextmat = AllocateComplexMatrix();
		if( n == 0 ) {
			nextmat[0][0] = 1.0; nextmat[0][1] = 0.0; nextmat[0][2] = 0.0;
			nextmat[1][0] = 0.0; nextmat[1][1] = 1.0; nextmat[1][2] = 0.0;
			nextmat[2][0] = 0.0; nextmat[2][1] = 0.0; nextmat[2][2] = 1.0;
		} else {
			// n >= 1
			for( int i = 0; i < r; i++ ) {
				for( int j = 0; j < c; j++ ) {
					nextmat[i][j] = 0.0;
					for( int k = 0; k < 3; k++ ) {
						nextmat[i][j] += cmat[i][k] * cmat[k][j] ;
					}
					nextmat[i][j] /= n;
				}
			}
		}

		// Add nextmat to the sum
		for( int i = 0; i < r; i++ ) {
			for( int j = 0; j < c; j++ ) {
				cmat[i][j] += nextmat[i][j];
			}
		}
	}
}
