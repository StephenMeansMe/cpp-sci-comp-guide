/*
 * example6_7.cpp
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

#include "Book.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Book good_read;

	good_read.author = "C S Lewis";
	good_read.title = "The silver chair";
	good_read.publisher = "Geoffrey Bles";
	good_read.price = 699;
	good_read.format = "paperback";
	good_read.SetYearOfPublication(1953);

	Book another_book(good_read);

	Book an_extra_book("The Magician's nephew");

	return 0;
}

