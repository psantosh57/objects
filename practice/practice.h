#include "../util/util.h"

#ifndef PRACTICE_H
#define PRACTICE_H


class practice {

public:
	
	void give_name() const;
	void give_age() const;
	void set_name(const char*);
	void set_age(const int age);
	void fini();

private:

	char* _name;
	int _age;


};

class student {

public:

	void init(const char* str, int n);
	void fini();
	void print();

private:

	int _id;
	char* _stuName;

};

#endif