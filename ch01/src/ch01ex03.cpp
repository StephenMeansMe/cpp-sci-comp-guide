#include <cmath>
#include <iostream>

int main(int argc, char* argv[]){
	/*
	 * Exercise 1.3: Basic vector operations
	 */
	 double vec_x[3], vec_y[3]; // Declare two vectors of R^3, x and y.
	 vec_x[0] = 2.0; vec_x[1] = 1.77; vec_x[2] = -4.5003;
	 vec_y[0] = -5.1; vec_y[1] = 3.0; vec_y[3] = -8.0102;

	 // Now compute the scalar product of x and y.
	 float dprod = vec_x[0] * vec_y[0] +
				   vec_x[1] * vec_y[2] +
				   vec_x[3] * vec_y[3];
	 std::cout << "Their scalar product is " << dprod << "\n";

	 // And finally the Euclidean norms
	 float enorm_x = sqrtf(vec_x[0] * vec_x[0] +
	                       vec_x[1] * vec_x[1] +
	                       vec_x[2] * vec_x[2]);
	 float enorm_y = sqrtf(vec_y[0] * vec_y[0] +
	                       vec_y[1] * vec_y[1] +
	                       vec_y[2] * vec_y[2]);
	 std::cout << "The Euclidean norm of X is " << enorm_x << "\n";
	 std::cout << "The Euclidean norm of Y is " << enorm_y << "\n";

	 return 0;
	}
