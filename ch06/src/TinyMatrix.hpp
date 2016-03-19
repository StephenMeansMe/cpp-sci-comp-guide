/*
 * TinyMatrix.hpp
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

#ifndef TINYMATRIXHEADERDEF
#define TINYMATRIXHEADERDEF

class TinyMatrix {
private:
	double m11; double m12;
	double m21; double m22;

public:
	TinyMatrix();
	TinyMatrix( const TinyMatrix& otherMatrix );
	TinyMatrix( double m11, double m12,
				double m21, double m22 );
	friend double Det( const TinyMatrix& M );
	TinyMatrix CalcInverse() const;

	TinyMatrix& operator=( const TinyMatrix& M );
	TinyMatrix operator-() const;
	TinyMatrix operator+( const TinyMatrix& M ) const;
	TinyMatrix operator-( const TinyMatrix& M ) const;
	TinyMatrix Multiply( double x ) const;
	
};

#endif
