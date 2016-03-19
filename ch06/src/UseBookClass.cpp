/*
 * UseBookClass.cpp
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

#include <iostream>
#include "Book.hpp"

int main(int argc, char **argv)
{
	Book promotion_book;

	promotion_book.author    = "Iris Murdoch";
	promotion_book.title     = "The sea, the sea";
	promotion_book.publisher = "Chatto & Windus";
	promotion_book.price     = 299;
	promotion_book.format    = "hardback";
	promotion_book.SetYearOfPublication( 1978 );

	std::cout << "Year of publication of "
			  << promotion_book.title << " is "
			  << promotion_book.GetYearOfPublication()
			  << "\n";

	return 0;
}

