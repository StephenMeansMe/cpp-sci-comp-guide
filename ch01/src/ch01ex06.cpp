#include <iostream>

int main(int argc, char* argv[])
{
	int cars[5]; double cars_avg = 0.0;
	std::cout << "Cars on first day: ";
	std::cin >> cars[0];
	cars_avg += ((double)(cars[0]));

	std::cout << "Cars on second day: ";
	std::cin >> cars[1];
	cars_avg += ((double)(cars[1]));

	std::cout << "Cars on three day: ";
	std::cin >> cars[2];
	cars_avg += ((double)(cars[2]));

	std::cout << "Cars on fourth day: ";
	std::cin >> cars[3];
	cars_avg += ((double)(cars[3]));

	std::cout << "Cars on fifth day: ";
	std::cin >> cars[4];
	cars_avg += ((double)(cars[4]));
	
	cars_avg /= 5; // Divide by number of days
	std::cout << "The average number of cars per day is " << cars_avg << ".\n";
}
