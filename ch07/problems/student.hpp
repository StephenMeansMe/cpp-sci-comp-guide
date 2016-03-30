/*
 * student.hpp
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

#ifndef STUDENTDEF
#define STUDENTDEF

class Student {
public:

	Student( double t = 0.0, double f = 0.0 );

	double tuitionFees;
	
	void SetLibraryFines( double f );
	double GetLibraryFines();
	virtual double GetTotalMoneyOwed();

private:
	double mLibraryFines;

};

class GradStudent: public Student {
public:

	GradStudent( bool pt = false );
	void SetPartTime( bool pt );
	void SetLibFineMult( double fm );
	void SetTuitionMult( double tm );

	bool IsPartTime();
	double GetTotalMoneyOwed();
	double GetLibFineMult();
	double GetTuitionMult();

private:

	bool   mPartTime;
	double mLibFineMult;
	double mTuitionMult;

};

class PhDStudent: public GradStudent {
public:

	PhDStudent( bool pt = true );

};

#endif // STUDENTDEF
