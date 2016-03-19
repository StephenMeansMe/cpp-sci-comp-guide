/*
 * ComplexNumber.cpp
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

#include "ComplexNumber.hpp"
#include <cmath>

// Override default constructor
ComplexNumber::ComplexNumber() {
	// Set real and imaginary parts to zero
	mPart_Re = 0.0;
	mPart_Im = 0.0;
}

// Constructor that sets complex number z = x + (i * y)
ComplexNumber::ComplexNumber( double x, double y ) {
	mPart_Re = x;
	mPart_Im = y;
}

// Overwritten copy constructor
ComplexNumber::ComplexNumber(const ComplexNumber& other_z ) {
	mPart_Re = other_z.GetRe();
	mPart_Im = other_z.GetIm();
}

// Constructor to allow, e.g., ComplexNumber z(1.0) --> z = 1.0 + 0.0i
ComplexNumber::ComplexNumber( double r ) {
	mPart_Re = r;
	mPart_Im = 0.0;
}

// Methods for accessing the private members
double ComplexNumber::GetRe() {
	return mPart_Re;
}

double ComplexNumber::GetIm() {
	return mPart_Im;
}

// Friend functions `Re` and `Im` so one can write `z.GetIm` or `Im(z)`
double Re( const ComplexNumber& z ) {
	return z.mPart_Re;
}

double Im( const ComplexNumber& z ) {
	return z.mPart_Im;
}

// Method for computing the modulus of a complex number
double ComplexNumber::CalculateMod() const {
	return sqrt( mPart_Re * mPart_Re + mPart_Im * mPart_Im );
}

// Method for computing the argument of a complex number
double ComplexNumber::CalculateArg() const {
	return atan2( mPart_Im, mPart_Re );
}

// Method for raising a complex number to the power n using de Moivre's theorem
// First the complex number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePow( double n ) {
	double mod = CalculateMod();
	double arg = CalculateArg();

	double mod_of_result = pow( mod, n );
	double arg_of_result = arg * n;

	double part_re = mod_of_result * cos( arg_of_result );
	double part_im = mod_of_result * sin( arg_of_result );

	ComplexNumber z( part_re, part_im );
	return z;
}

// Method for computing the complex conjugate `x - iy` of a complex number `x + iy`.
ComplexNumber ComplexNumber::CalculateConjugate() const {
	ComplexNumber w;
	w.mPart_Re = mPart_Re;
	w.mPart_Im = -mPart_Im;
	return w;
}

// Method to set the complex number `x + iy` to its conjugate `x - iy`
void ComplexNumber::SetConjugate() {
	mPart_Im = -mPart_Im;
}

// Overloading the = (assignment) operator
ComplexNumber& ComplexNumber::operator=( const ComplexNumber& z ){
	mPart_Re = z.mPart_Re;
	mPart_Im = z.mPart_Im;
	return *this;
}

// Overloading the unary - operator
ComplexNumber& ComplexNumber::operator-() const {
	ComplexNumber w;
	w.mPart_Re = -mPart_Re;
	w.mPart_Im = -mPart_Im;
	return w;
}

// Overloading the binary + operator
ComplexNumber& ComplexNumber::operator+( const ComplexNumber& z ) const {
	ComplexNumber w;
	w.mPart_Re = mPart_Re + z.mPart_Re;
	w.mPart_Im = mPart_Im + z.mPart_Re;
	return w;
}

// Overloading the binary - operator
ComplexNumber& ComplexNumber::operator-( const ComplexNumber& z ) const {
	ComplexNumber w;
	w.mPart_Re = mPart_Re - z.mPart_Re;
	w.mPart_Im = mPart_Im - z.mPart_Im;
}

// Overloading the insertion << operator
std::ostream& operator<<( std::ostream& output,
						  const ComplexNumber& z ) {
	ComplexNumber w;
	// Format as "(a + bi)" or as "(a - bi)"
	output << "(" << z.mPart_Re << " ";
	if( z.mPart_Im >= 0.0 ) {
		output << "+ " << z.mPart_Im << "i)";
	} else {
		// Im(z) < 0.0, replace plus sign with minus sign
		output << "- " << -z.mPart_Im << "i)";
	}
}
