//Alex Feldman
//Computer Architecture

#include <stdio.h>
#define triArea(height, base) ((height * base)/2.0)



int expression_solver(int a, int b, int c){
	// problem 2
	return ((b * b) - 4 * a * c) / 2.0 * a;
}


int main() {
// problem 1
	int triangleBase = 2;
	int triangleHeight = 5;
	printf("the area of this triangle is %d\n", 
		triArea(triangleHeight, triangleBase));


	printf("The answer to problem 3 should be NONE,\nhowever, default is spelled wrong, so this code does not produce anything.\n");

}