/*
 * friend_example.cpp
 * 
 * Copyright 2016 Stephen <me@stephenmeansme.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
e * 
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

#include "friend_example.hpp"

// Constructor to set private members
ExampleClass::ExampleClass( double member1, double member2 ) {
	mMemberVariable1 = member1;
	mMemberVariable2 = member2;
}

// GetMinimum is a member method
double ExampleClass::GetMinimum() const {
	if( mMemberVariable1 < mMemberVariable2 ) {
		return mMemberVariable1;
	} else {
		// mMemberVariable1 >= mMemberVariable2
		return mMemberVariable2;
	}
}

// GetMaximum is a friend function
double GetMaximum( const ExampleClass& egClass ) {
	if( egClass.mMemberVariable1 > egClass.mMemberVariable2) {
		return egClass.mMemberVariable1;
	} else {
		// egClass.Var1 <= egClass.Var2
		return egClass.mMemberVariable2;
	}
}
