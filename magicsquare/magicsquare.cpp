#include "magicsquare.h"

void magicsquare::print_magic_square(int n) {
	
	int size = n*n;
	int r0 = 0;
	int r1 = n;
	int count = 0;
	int *magicArray = new int [size];

	for (int r = 0; r < size; r++) {

		magicArray[r] = 0;
	}

	fillArray(magicArray, n);

	displayArray(magicArray, n);

	//sumOfColumns(magicArray, n);
	//sumOfRows(magicArray, n);
	//sumOfDiag(magicArray, n);
	cout << "Calculating and verifying sum of rows, columns and diagonals for matrix of size " << n << endl;
	grandSum(magicArray, n);

	delete[] magicArray;
}

void magicsquare::fillArray(int* arr, int n) {

	int nextIndex = 0;
	int newRow = 0;
	int newCol = n / 2;

	//Setting first element to 1
	//arr[calcIndex(0, n / 2, n)] = 1;
	
	for (int i = 1; i <= (n*n); i++) {

		if (i == 1) {
			arr[calcIndex(newRow, newCol, n)] = i;
		}
		else {

			nextIndex = giveNextIndex(arr, newRow, newCol, n);
			arr[nextIndex] = i;
			newRow = nextIndex / n;
			newCol = nextIndex % n;
		}

		

	}

}

int magicsquare::giveNextIndex(int* arr, int r, int c, int n) {

	if (r == 0 && c == 0) {

		if (arr[calcIndex((n - 1), (n - 1), n)] != 0) {

			r = (r + 1);
		}
		else {

			r = (n - 1);
			c = (n - 1);

		}
		
		
	}
	else if (r == 0 && c != 0) {

		r = (n - 1);
		c = (c - 1);

	}
	else if (r != 0 && c == 0) {

		r = (r - 1);
		c = (n - 1);
	}
	else if (r != 0 && c != 0) {

		if (arr[calcIndex((r-1), (c-1), n)] != 0) {

			r = (r + 1);
		}
		else {

			r = (r - 1);
			c = (c - 1);

		}
	}


	return calcIndex(r, c, n);
}

int magicsquare::calcIndex(int r, int c, int n) {

	return (r*n + c);
}

void magicsquare::displayArray(int* arr, int n) {

	int count = 0;

	for (int r = 0; r < n; r++) {

		for (int c = 0; c < n; c++) {

			cout << arr[(r*n)+c]<< " ";
		}

		cout << endl;
	}

}

/*
void magicsquare::sumOfColumns(int* arr, int n) {

	int count = (n*n);
	int sum = 0;

	for (int col = 0; col < n; col++) {

		for (int i = col; i < count; i += n) {

			sum += arr[i];
		}

		cout << "Sum of column "<< col <<" is " << sum << endl;
		sum = 0;

	}

}

void magicsquare::sumOfRows(int* arr, int n) {

	int count = (n*n);
	int sum = 0;

	for (int row = 0; row < n; row++) {

		for (int i = 0; i < n; i++) {

			sum += arr[i];
		}

		cout << "Sum of row " << row << " is " << sum << endl;
		sum = 0;

	}

}

void magicsquare::sumOfDiag(int* arr, int n) {

	int count = (n*n);
	int sum = 0;

	for (int row = 0; row < n; row++) {

		sum += arr[(row*n)+row];

	}

	cout << "Sum of diag 1 is " << sum << endl;
	sum = 0;

	for (int row = (n-1); row >= 0; row--) {

		sum += arr[(row*n) + row];

	}

	cout << "Sum of diag 2 is " << sum << endl;

}

*/


void magicsquare::grandSum(int* arr, int n) {

	int size = ((2 * n) + 2);
	int* sumArray = new int [size];
	int count = 0;
	int sum = 0;
	bool ifMismatch = false;
	
	//Sum of rows
	for (int row = 0; row < n; row++) {

		for (int i = 0; i < n; i++) {

			sum += arr[((row*n)+i)];
			
		}

		//cout << "Sum of row " << row << " is " << sum << endl;
		sumArray[count++] = sum;
		sum = 0;

	}

	sum = 0;

	//Sum of columns
	for (int col = 0; col < n; col++) {

		for (int i = col; i < (n*n); i += n) {

			sum += arr[i];
		}

		//cout << "Sum of column " << col << " is " << sum << endl;
		sumArray[count++] = sum;
		sum = 0;

	}

	sum = 0;

	//Sum of diagonals
	for (int row = 0; row < n; row++) {

		sum += arr[(row*n) + row];

	}

	//cout << "Sum of diag 1 is " << sum << endl;
	sumArray[count++] = sum;
	sum = 0;

	for (int row = (n - 1); row >= 0; row--) {

		sum += arr[(row*n) + row];

	}

	//cout << "Sum of diag 2 is " << sum << endl;
	sumArray[count++] = sum;
	sum = 0;

	for (int ind = 1; ind < (size); ind++) {

		//cout << sumArray[ind] << " ";

		if (sumArray[0] != sumArray[ind]) {
			ifMismatch = true;
			break;
		}

	}

	cout << endl;

	if (ifMismatch) {

		cout << "Sums of rows, columns and diagonals don't match" << endl;
	}
	else {

		cout << "Sums of rows, columns and diagonals match!" << endl;
	}

	cout << endl << endl;

	delete[] sumArray;
}