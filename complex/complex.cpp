#include "complex.h"

complex::complex(int real, int imag) :_real(real), _imag(imag) {

	cout << "In complex constructor" << endl;
	
	fillName(_real, _imag);

}

complex::~complex() {

	cout << "In complex destructor " << endl;

	delete[] _name;
}

complex::complex(const complex& rhs) {

	cout << "In copy constructor" << endl;
	_copy(rhs);

}

bool complex::operator==(const complex& rhs) {

	cout << "In operator == " << endl;
	if (this != &rhs) {
		return (this->_real == rhs._real && this->_imag == rhs._imag) ? true : false;
			
	}

}

bool complex::operator!=(const complex& rhs) {

	cout << "In operator != " << endl;
	if (this != &rhs) {
		return (this->_real != rhs._real || this->_imag != rhs._imag) ? true : false;

	}

}

complex& complex::operator=(const complex& rhs) {

	if (this != &rhs) {
		_release();
		_copy(rhs);

	}

	return *this;

}

void complex::_release() {

	delete[] _name;

}

void complex::_copy(const complex& rhs) {

	_name = copyString(rhs._name, _name);
	_real = rhs._real;
	_imag = rhs._imag;

}

char* complex::copyString(const char* src, char* dst) {
	
	int size = getLength(src);
	dst = new char[size+1];
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
	//int count = 0;

	while (str[i] != '\0') {
		//count++;
		i++;
	}

	return i;

}

void complex::print() {

	cout << "Complex number is "<< _name << endl;

}

int complex::getNumDigits(int n, bool isImag = false) {

	//cout << "Got digit " << n << endl;
	int count = 0;


	if (n < 0) {

		if (!isImag) {
			count++;
			
		}

		n *= -1;

	}	

	while (n > 0) {
		count++;
		n /= 10;
	}

	return count;
}

void complex::fillName(int real, int imag) {

	//cout << "Got real " << real << " and imag " << imag << endl;

	int size = 1;
	int real_size = 1;
	int imag_size = 1;

	if (real == 0 && imag == 0) {

		size++;
		_name = new char[size];
		_name = "0";

	}
	else {

		real_size += getNumDigits(real);
		imag_size += getNumDigits(imag, true);
		//cout << "Real size " << real_size << endl;
		//cout << "Imag size " << imag_size << endl;
		size += real_size + imag_size; //For +/- sign and 'i'
	}

	_name = new char[size];

	char * realStr = new char[real_size];
	char* imagStr = new char[imag_size];

	realStr = intToChar(realStr, real, real_size);
	imagStr = intToChar(imagStr, imag, imag_size);
	
	int index = 0;
	
	index = strAppend(_name, realStr, index);

	if (imag < 0) {
		_name[index] = '-';
	}
	else {
		_name[index] = '+';
	}

	index++;
	
	_name[index] = 'i';
	
	index++;

	index = strAppend(_name, imagStr, index);

	_name[index] = '\0';

}

char* complex::intToChar(char* arr, int n, int count) {
	
	//cout << "Got n " << n << endl;

	int i = (count-1);
	int m = n;
	if (n < 0) {
		n *= -1;
	}
	
	arr[i] = '\0';
	i--;
	
	while (n > 0) {
		arr[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}

	if (m < 0) {
		arr[i] = '-';
	}	

	return arr;
	

}

int complex::strAppend (char*& name, char* str, int ind = 0) {

	int i = 0;

	while (str[i] != '\0') {

		name[ind] = str[i];
		i++;
		ind++;

	}

	return ind;
	
}

void complex::setxy(int real, int imag) {

	if (this->_real == real && this->_imag == imag) {

		cout << "Trying to set same number" << endl;
	}

	else {
		_release();
		_real = real;
		_imag = imag;
		fillName(real, imag);
	}

}

void complex::remove(char* str) {

	delete[] str;
}