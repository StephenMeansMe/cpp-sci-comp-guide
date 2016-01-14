/*
 * swap_vars.cpp
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


#include "swap_vars.h"

void swap_vars(double *var)
{

	double *swap = new double;
	*swap = var[2];
	var[2] = var[1];
	var[1] = *swap;
	delete swap;
}

void swap_vars(double &var1, double &var2)
{
	double *swap = new double;
	*swap = var2;
	var2 = var1;
	var1 = *swap;
	delete swap;	
}
