#include "../util/util.h"

#ifndef MAGICSQUARE_H
#define MAGICSQUARE_H



class magicsquare {

public:

	void print_magic_square(int n);
	

private:

	void displayArray(int* arr, int n);
	int calcIndex(int row, int column, int n);
	int giveNextIndex(int* array, int row, int column, int n);
	void fillArray(int* array, int n);

	/*
	void sumOfRows(int* array, int n);
	void sumOfColumns(int* array, int n);
	void sumOfDiag(int* array, int n);
	*/
	void grandSum(int* array, int n);


};

#endif
