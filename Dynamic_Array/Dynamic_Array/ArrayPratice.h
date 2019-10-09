/*****************************************************
** Samuel Mendheim~ COMP233 Fall 2019 ~ Dynamic Memory
** This program uses pointers to manipulate arrays
*****************************************************/

#include <malloc.h>
#include <iostream>
using namespace std;
char* ary = NULL;

//declaring all methods
void method1(int rows, int cols);
void method2(int cols);
void method3(int rows, int cols);
void method4(char* array, int x, int y, int z);
void method5(int x);



int main() {

	cout << "Dynamic Array Allocation ~ COMP233\n\n";
	
	// calling all methods
	method1(4, 5);
	method2(4);
	method3(8, 3);
	method4(ary, 5,5,5);
	method5(7);


	cout << "\n\n\t< normal termination >\n" << endl;
	return 0;
}

// this method does problem 1
void method1(int rows, int cols) {

	cout << "***** Problem 1 *****" << "\n";

	// creating an array of points 
	double* x = (double*)malloc(rows * cols * sizeof(double));

	// setting each value to 9.99
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			*(x + i * cols + j) = 9.99;
		}
	}
	// chaning the value of index [2][1] to 1.23
	*(x + 2 * cols + 1) = 1.23;

	// printing out the values stored within the array
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << *(x + i * cols + j) << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
	// freeing up the memory
	free(x);
}

// this method does problem 2
void method2(int cols) {

	cout << "***** Problem 2 *****" << "\n";

	// setting rows as a constant
	const int rows = 3;

	// allocating a set amount of memory for the pointer array
	double* a[rows];

	// creating that memory
	for (int i = 0; i < rows; i++) {
		a[i] = (double*)malloc(cols * sizeof(double));
	}

	// adding values to every index of the array
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			*(a[i] + j) = 9.99;
		}
	}

	// chaning the value of index [1][3] to 4.56
	*(a[1] + 3) = 4.56;

	// printing out all the content of the array
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << *(a[i] + j) << "\t";
		}
		cout << "\n";
	}
	cout << "\n";

	// freeing up all that sweet good memory
	for (int i = 0; i < rows; i++) {
		free(a[i]);
	}
}

// this method does problem 3
void method3(int rows, int cols) {

	cout << "***** Problem 3 *****" << "\n";

	// creating a pointer array with the rows and cols entered
	double** b = (double**)malloc(rows * sizeof(double*));

	// allocating that memory to the pointer array
	for (int i = 0; i < rows; i++) {
		b[i] = (double*)malloc(cols * sizeof(double));
	}

	// adding 9.99 to every value in the array
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			*(*(b + i) + j) = 9.99;
		}
	}
		
	// chaning the value of index [4][2] to 5.67
	*(*(b + 4) + 2) = 5.67;

	// printing out all the values of the array
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << *(*(b + i) + j) << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
		
	// freeing up all that memory 
	free(b);
}

// this method does problem 4
void method4(char * array, int x, int y, int z) {

	// allocating enough memory for the pointer array
	array = (char*)malloc(x * y * z * sizeof(char));

	cout << "***** Problem 4 *****" << "\n";
	
	// initiallizing all of the values inside of the array
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++) {
				*(array + i * y * z + j * z + k) = ' ';
				//*(array + i * x + y * j + z * k) = ' ';
			}
		}
	}

	// initializing [2][j][3] to X
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++) {
				*(array + 2 * y * z + j * z + 3) = 'X';
			}
		}
	}

	// printing out the array
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++) {
				cout << *(array + i * y * z + j * z + k) << "\t";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	cout << "\n";
	
	// freeing up the memory
	free(array);
}

// this method does problem 5
void method5(int x) {

	cout << "***** Problem 5 *****" << "\n";

	// allocating the memory for the pointer array
	double* array = (double*)malloc(x * x * sizeof(double));

	// for loops to create the multiplication table
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			*(array + i * x + j) = (i+1)*(j+1);
		}
	}

	// for loop to print out the table
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			cout << *(array + i * x + j) << "\t";
		}
		cout << "\n";
	}

	// freeing the array
	free(array);
}
