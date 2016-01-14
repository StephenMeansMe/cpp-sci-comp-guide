/*
 * Exercise4-2.cpp
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


#include <iostream>

int main(int argc, char **argv)
{
	int x = 0;
	int y = 1;
	std::cout << "x = " << x << "\t y = " << y << "\n";
	std::cout << "&x = " << &x << "\t &y = " << &y << "\n"; 

	int* p_x; int* p_y;
	p_x = new int [1];
	p_y = new int [1];
	std::cout << "p_x = " << p_x << "\t p_y = " << p_y << "\n";

	*p_x = y;
	*p_y = x;

	x = *p_x;
	y = *p_y;
	delete p_x;
	delete p_y;
	std::cout << "x = " << x << "\t y = " << y << "\n";
	std::cout << "&x = " << &x << "\t &y = " << &y << "\n";
	
	return 0;
}

