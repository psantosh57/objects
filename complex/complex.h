#include "../util/util.h"

#ifndef COMPLEX_H
#define COMPLEX_H

class complex {

public:
	complex(const int real = 0, const int imag = 0);
	complex(const complex& rhs);
	bool operator==(const complex& rhs);
	bool operator!=(const complex& rhs);
	complex& operator=(const complex& rhs);
	~complex();
	void print();
	void setxy(int real, int imag);


private:

	int _real;
	int _imag;
	char* _name;
	
	bool isNeg;
	int getLength(const char* str);
	void _copy(const complex& rhs);
	void _release();
	char* copyString(const char* src, char* dst);
	int getNumDigits(int n, bool isImag);
	void fillName(int real, int imag);
	char* intToChar(char* arr, int n, int numDigits);
	int strAppend(char*& name, char* str, int index);
	void remove(char* str);

};


#endif