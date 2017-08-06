#include "practice.h"

void practice::give_name() const {

	cout << "My name is "<<_name << endl;

}

void practice::set_name(const char* str) {

	int i = 0;
	int count = 0;
	while (str[i] != '\0') 	{
		count++;
		i++;
	}
	
	_name = new char[count+1];
	i = 0;
	while (str[i] != '\0') {
		_name[i] = str[i];
		i++;
	}

	_name[i] = '\0';
	
}

void practice::set_age(int age) {

	_age = age;
}

void practice::give_age() const {

	cout << _name << "'s age is " << _age << endl;;
}

void practice::fini() {

	delete[] _name;
}


//////////////////////////////////////////////////////////////////////////////////////

void student::init(const char* str, int n) {

	int count = 0;
	int i = 0;

	while (str[i] != '\0') {

		count++;
		i++;
	}

	_stuName = new char[count + 1];

	i = 0;

	while (str[i] != '\0') {

		_stuName[i] = str[i];
		i++;
	}

	_stuName[i] = '\0';

	_id = n;
}

void student::fini() {

	delete[] _stuName;
}

void student::print() {

	cout << "Student name " << _stuName << endl;
	cout << "Student ID " << _id << endl;
}
