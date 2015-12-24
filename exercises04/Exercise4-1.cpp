/*
 * Exercise4-1.cpp
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
	int i = 5;
	int* p_j = &i;
	int* p_k;

	*p_j = *p_j * 5;
	std::cout << &i << "\t" << i << "\n";
	std::cout << p_j << "\t" << *p_j << "\n";
	p_k = new int [1];
	*p_k = i;
	std::cout << p_k << "\t" << *p_k << "\n";
	
	return 0;
}

