/*
 * ComplexNumber.hpp
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

#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

#include <iostream>

class ComplexNumber {
private:
	double mPart_Re;
	double mPart_Im;

public:
	ComplexNumber();
	ComplexNumber( double x, double y );
	double CalculateMod() const;
	double CalculateArg() const;
	ComplexNumber CalculatePow( double n ) const;
	ComplexNumber& operator=( const ComplexNumber& z );
	ComplexNumber operator-() const;
	ComplexNumber operator+( const ComplexNumber& z ) const;
	ComplexNumber operator-( const ComplexNumber& z ) const;
	friend std::ostream& operator<<( std::ostream& output,
									 const ComplexNumber& z );
};

#endif
