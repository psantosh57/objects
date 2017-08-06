#include "../util/util.h"

#ifndef INTMATRIX1_H
#define INTMATRIX1_H


class intmatrix1 {

public:

	void init();
	void init(int row, int column, int elements = 0);
	void init(const char * c);
	void print(const char* c);
	void fini();
	bool isEmpty();
	bool isEqual(intmatrix1 rhs);
	intmatrix1 add(intmatrix1 rhs);
	intmatrix1 mult(intmatrix1 rhs);

private:

	bool isDigit(char ch);
	void display(int* mat, int rows, int cols);
	void fillMatrix(int*& mat, int row, int col, const char* str);
	int toDigit(char ch);
	int *matrix;
	int row;
	int column;
};

#endif