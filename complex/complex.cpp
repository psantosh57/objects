#include "complex.h"

complex::complex(int real, int imag) :_real(real), _imag(imag) {

	cout << "In complex constructor" << endl;
	cout << "Setting real to " << real << " and imag to " << imag << endl;
	
	int size = 0;

	if (_real == 0 && _imag == 0) {

		size = 2;
		_name = new char[size];
		_name = "0";

	}
	else {

		size += getNumDigits(_real);
		size += getNumDigits(_imag);
		size++;
	}

}

complex::~complex() {

	delete[] _name;
}

complex::complex(const complex& rhs) {

	cout << "In copy constructor" << endl;
	_copy(rhs);


}

complex& complex::operator=(const complex& rhs) {

	cout << "In operator = " << endl;
	if (this != &rhs) {

		_release();
		_copy(rhs);

	}

}

void complex::_release() {

	delete[] _num;
}

void complex::_copy(const complex rhs) {

	_num = copyString(_num, rhs._num);
	_real = rhs._real;
	_imag = rhs._imag;

}

char* complex::copyString(const char* src, char* dst) {
	
	int size = getLength(src);
	dst = new char[size];
	int i = 0;
	while (src[i] != '\0') {

		dst[i] = src[i];
		i++;
	}

	dst[i] = '\0';

	return dst;
}

int complex::getLength(const char* str) {

	int i = 0;
	int count = 0;

	while (str[i] != '\0') {
		count++;
		i++;
	}

	return i;

}

void complex::print() {

	cout << _name << endl;

}

int complex::getNumDigits(int n) {

	int count = 0;
	while (n > 0) {
		count++;
		n /= 10;
	}

	return count;
}

