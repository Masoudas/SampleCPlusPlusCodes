#include <iostream>

void OneDArrays(void) {
	int mat[3] = { 1, 2, 3 };

	int* x = nullptr;
	for (int i = 0; i < 2; i++) {
		x = mat + i;

		std::cout << (mat + i) << "\n";
		std::cout << *(mat + i) << "\n";
		std::cout << *x << "\n";
	}

	// Here's something very interesting. Suppose we define a constant array. If we copy it normally into another integer, then it's ok.
	// However, when referencing it, it should be constant
	const int arr[2] = { 1, 2 };
	int elem = arr[0];

	const int& elem0 = arr[0];
	// int& elem0 = arr[0]; This would be wrong.

}

void TwoDArray(void) {
	// Ok, le premier dimention est "row", et la deuxieme est "column".
	int mat[2][3] = { {1, 2, 3}, {4, 5, 5} };


	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << mat[i][j] << "\n";
			std::cout << *(mat[i] + j) << "\n";
			std::cout << *(*(mat + i) + j) << "\n";
		}
	}
}


//int allocate(int* A, int n) { 
//	if ((A = malloc(n * sizeof(int))) != NULL)          
//		return 0;      
//	return 1; 
//}

void pass2DArray1(int A[][3]) {
	int i, j;
	for (i = 0; i < 3; i++) {
		printf("\n");
		for (j = 0; j < 3; j++) printf("%4.2d", A[i][j]);
	}
	printf("\n");

}

void pass2DArray2(int(*A)[3]) {
	/* Second method of passing arrays. We are passing an array of pointer (A[]=(*A)) to the function. 3 is the second dimension*/
	int i, j;         
	for (i = 0; i < 3; i++) { 
		printf("\n");                 
		for (j = 0; j < 3; j++) printf("%4.2d", A[i][j]); 
	} 
	printf("\n");
}


void pass2DArray3(int *A) {
	/* Flatted passing. We pass a pointer to array.*/
	int i, j;         
	for (i = 0; i < 3; i++) { 
		printf("\n");                 
		for (j = 0; j < 3; j++) 
			printf("%4.2d", *(A + 3 * i + j)); 
	} 
	printf("\n");
}


void copyArray(void) {
	// In order to copy arrays, we have to loop through.
	// As we of course know, direct assignment does not copy an array.
	// Other types of arrays and lists have certain functions for such copy, like the array class.
	int x1[2] = { 1, 2 };
	int x2[2] = {};

	int* ptr = x2;
	for (int x : x1) {
		*ptr++ = x;
	}

	std::cout << x2[0] << " " << x2[1];
}