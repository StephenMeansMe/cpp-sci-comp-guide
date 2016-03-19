/*
 * TinyMatrix.cpp
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

#include "TinyMatrix.hpp"
#include <cassert>

TinyMatrix::TinyMatrix() {
	m11 = 0.0; m12 = 0.0;
	m21 = 0.0; m22 = 0.0;
}

TinyMatrix::TinyMatrix( const TinyMatrix& otherMatrix ) {
	m11 = otherMatrix.m11; m12 = otherMatrix.m12;
	m21 = otherMatrix.m21; m22 = otherMatrix.m22;
}

TinyMatrix::TinyMatrix( double x11, double x12,
						double x21, double x22 ) {
	m11 = x11; m12 = x12;
	m21 = x21; m22 = x22;
}

double TinyMatrix::CalcDet() {
	double d = m11 * m22 - m12 * m21;
	assert( d > 0 );
	return 1 / d;
}

TinyMatrix TinyMatrix::CalcInverse() const {
	double d = CalcDet();
	TinyMatrix M;
	M.m11 = d * m11; M.m12 = d * m12;
	M.m21 = d * m21; M.m22 = d * m22;
	return M;
}

TinyMatrix& TinyMatrix::operator=( const TinyMatrix& M ) {
	m11 = M.m11; m12 = M.m12;
	m21 = M.m21; m22 = M.m22;
	return *this;
}

TinyMatrix TinyMatrix::operator-() const {
	TinyMatrix M;
	M.m11 = -m11; M.m12 = -m12;
	M.m21 = -m21; M.m22 = -m22;
	return M;
}

TinyMatrix TinyMatrix::operator+( const TinyMatrix& M ) const {
	TinyMatrix N;
	N.m11 = m11 + M.m11; N.m12 = m12 + M.m12;
	N.m21 = m21 + M.m21; N.m22 = m22 + M.m22; 
	return N;
}

TinyMatrix TinyMatrix::operator-( const TinyMatrix& M ) const {
	TinyMatrix N;
	N.m11 = m11 - M.m11; N.m12 = m12 - M.m12;
	N.m21 = m21 - M.m21; N.m22 = m22 - M.m22; 
	return N;
}

TinyMatrix TinyMatrix::Multiply( double x ) const {
	TinyMatrix M;
	M.m11 = x * m11; M.m12 = x * m12;
	M.m21 = x * m21; M.m22 = x * m22;
	return M;
}
