#include <cmath>
#include <iostream>

int main(int argc, char* argv[]){
	
	/*
	 * Exercise 1.4: Basic matrix operations
	 */
	double mA[2][2] = { {-1.2, 4.71}, {sqrtf(8), 0.9} };
	double mB[2][2] = { {9.9, -6.301}, {2.0, 0.0} };
	std::cout << "The matrix A has entries:\n"
	          << mA[0][0] << "\t" << mA[0][1] << "\n"
			  << mA[1][0] << "\t" << mA[1][1] << "\n";
	std::cout << "The matrix B has entries:\n"
	          << mB[0][0] << "\t" << mB[0][1] << "\n"
			  << mB[1][0] << "\t" << mB[1][1] << "\n";
	// Compute matrix sum C = A + B
	double mC[2][2] = { {mA[0][0] + mB[0][0], mA[0][1] + mB[0][1]},
						{mA[1][0] + mB[1][0], mA[1][1] + mB[1][1]} };
	std::cout << "The matrix C = A + B has entries:\n"
	          << mC[0][0] << "\t" << mC[0][1] << "\n"
			  << mC[1][0] << "\t" << mC[1][1] << "\n";
	// Compute the matrix product D = A * B
	double mD[2][2];
	mD[0][0] = mB[0][0] * mA[0][0] + mB[1][0] * mA[0][1];
	mD[0][1] = mB[0][0] * mA[0][1] + mB[1][0] * mA[1][1];
	mD[1][0] = mB[1][0] * mA[0][0] + mB[1][1] * mA[0][1];
	mD[1][1] = mB[1][0] * mA[0][1] + mB[1][1] * mA[1][1];
	std::cout << "The matrix D = A * B has entries:\n"
	          << mD[0][0] << "\t" << mD[0][1] << "\n"
			  << mD[1][0] << "\t" << mD[1][1] << "\n";

	return 0;
}
