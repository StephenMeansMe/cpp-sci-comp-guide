/*
 * example6_4_2.cpp
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
#include <iostream>

int main(int argc, char **argv)
{
	ComplexNumber z1( 4.0, 3.0 );

	std::cout << "z1 = " << z1 << "\n";
	std::cout << "|z1| = " << z1.CalculateMod() << "\n";
	std::cout << "Arg(z1) = " << z1.CalculateArg() << "\n";

	ComplexNumber z2;
	z2 = z1.CalculatePow( 3.0 );
	std::cout << "z2 = z1 * z1 * z1 = " << z2 << "\n";

	ComplexNumber z3;
	z3 = -z2;
	std::cout << "z3 = -z2 = " << z3 << "\n";

	ComplexNumber z4;
	z4 = z1 + z2;
	std::cout << "z1 + z2 = " << z4 << "\n";

	ComplexNumber zs[2];
	zs[0] = z1;
	zs[1] = z2;
	std::cout << "Second element of zs = " << zs[1] << "\n";
	
	return 0;
}
