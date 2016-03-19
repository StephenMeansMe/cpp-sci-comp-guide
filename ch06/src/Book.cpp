/*
 * Book.cpp
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
#include <cassert>

// This overrides the default constructor
Book::Book() {
	author     = "unspecified";
	title      = "unspecified";
	publisher  = "unspecified";
	format     = "unspecified";
}

// This overrides the default copy constructor
Book::Book(const Book& otherBook) {
	author    = otherBook.author;
	title     = otherBook.title;
	publisher = otherBook.publisher;
	format    = otherBook.format;
	price     = otherBook.price;

	mYearOfPublication = otherBook.GetYearOfPublication();
}

// Specialized constructor
Book::Book(std::string bookTitle) {
	title = bookTitle;
}

void Book::SetYearOfPublication( int year ) {
	assert( ( year > 1440 ) and ( year < 2020 ) );
	mYearOfPublication = year;
}

int Book::GetYearOfPublication() const {
	return mYearOfPublication;
}
