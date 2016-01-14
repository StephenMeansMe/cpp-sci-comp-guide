#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	/*
	 * Exercise 1.5: String processing
	 */

	std::string given_name; // First the given name
	std::cout << "Enter your given name: ";
	std::getline(std::cin, given_name);
	std::string family_name; // Now the family name
	std::cout << "Enter your family name: ";
	std::getline(std::cin, family_name);
	std::cout << "Your full name is "
			  << given_name
			  << " "
			  << family_name
			  << ".\n";

	return 0;
}
