/*
 * student.cpp
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

#include <ch07/problems/student.hpp>
#include <cassert>

Student::Student( double t, double f ) {

	tuitionFees    = t;
	SetLibraryFines( f );

}

double Student::GetTotalMoneyOwed() {

	return tuitionFees + mLibraryFines;

}

void Student::SetLibraryFines( double f ) {

	assert( f >= 0.0 );
	mLibraryFines = f;

}

double Student::GetLibraryFines() {

	return mLibraryFines;

}

GradStudent::GradStudent( bool pt ) : Student() {

	mPartTime = pt;
	SetLibraryFines(0.0);
	mLibFineMult  = 1.0;
	mTuitionMult  = 0.0;

}

double GradStudent::GetTotalMoneyOwed() {

	double f = GetLibraryFines() * GetLibFineMult();
	double t = tuitionFees * GetTuitionMult();
	return f + t; 

}

double GradStudent::GetLibFineMult() {

	return mLibFineMult;

}

double GradStudent::GetTuitionMult() {

	return mTuitionMult;
	
}

void GradStudent::SetPartTime( bool pt ) {

	mPartTime = pt;

}

bool GradStudent::IsPartTime() {

	return mPartTime;

}

void GradStudent::SetLibFineMult( double fm ) {
	
	assert( fm >= 0.0 );
	mLibFineMult = fm;

}

void GradStudent::SetTuitionMult( double tm ) {

	assert( tm >= 0.0 );
	mTuitionMult = tm;

}

PhDStudent::PhDStudent( bool pt ) : GradStudent() {

	SetPartTime(pt);
	SetLibFineMult(0.0);

}
