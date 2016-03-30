/*
 * pr07_01.cpp
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
#include <iostream>

int main(int argc, char **argv)
{
	Student 	std1;
	GradStudent std2;
	PhDStudent 	std3;

	std1.tuitionFees = 1500.0;
	std1.SetLibraryFines( 31.0 );
	std2.SetLibraryFines( 19.0 );
	std3.SetPartTime( true );

	std::cout << "Student #1 owes " << std1.GetTotalMoneyOwed() << "\n";
	std::cout << "Student #2 owes " << std2.GetTotalMoneyOwed() << "\n";
	std::cout << "Student #3 owes " << std3.GetTotalMoneyOwed() << "\n";

	return 0;
}

