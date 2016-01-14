#include <iostream>

int main(int argc, char* argv[]){
	/*
	 * Exercise 1.2: Takes two integers from user as input, prints their
	 * product to standard output.
	 */
	 int x, y, prod;
	 std::cout << "Enter two integers. First X, then Y:\n";
	 std::cin >> x >> y;
	 prod = x * y;
	 std::cout << "The product of your numbers is " << prod << ".\n";

	 return 0; 
}
