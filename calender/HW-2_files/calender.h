#ifndef CALENDER_H
#define CALENDER_H

#include "../util/util.h"

class calender {


public:

	void compute_day(const char*, int month, int day, int year);

private:

	//Function to get the letter associated with a particular year
	char getAlpha(int year);

};

#endif