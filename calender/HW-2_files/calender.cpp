#include "calender.h"

void calender::compute_day(const char* str, int month, int day, int year) {

	int numArray[14][12] = {

		{1, 4, 4, 7, 2, 5, 7, 3, 6, 1, 4, 6},
		{2, 5, 5, 1, 3, 6, 1, 4, 7, 2, 5, 7},
		{3, 6, 6, 2, 4, 7, 2, 5, 1, 3, 6, 1},
		{4, 7, 7, 3, 5, 1, 3, 6, 2, 4, 7, 2},
		{5, 1, 1, 4, 6, 2, 4, 7, 3, 5, 1, 3},
		{6, 2, 2, 5, 7, 3, 5, 1, 4, 6, 2, 4},
		{7, 3, 3, 6, 1, 4, 6, 2, 5, 7, 3, 5},
		{1, 4, 5, 1, 3, 6, 1, 4, 7, 2, 5, 7},
		{2, 5, 6, 2, 4, 7, 2, 5, 1, 3, 6, 1},
		{3, 6, 7, 3, 5, 1, 3, 6, 2, 4, 7, 2},
		{4, 7, 1, 4, 6, 2, 4, 7, 3, 5, 1, 3},
		{5, 1, 2, 5, 7, 3, 5, 1, 4, 6, 2, 4},
		{6, 2, 3, 6, 1, 4, 6, 2, 5, 7, 3, 5},
		{7, 3, 4, 7, 2, 5, 7, 3, 6, 1, 4, 6}

	};

	char* dayArray[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	char yearAlpha = 'z';
	int alphaArrayIndex = 0;
	int numMonth = 0;
	
	if (day > 31 || day < 1) {

		cout << "Not a valid option" << endl;

	} 
	else if (year < 1755 || year > 2033) {

		cout << "Not a valid option" << endl;

	}
	else if (month < 1 || month > 12) {

		cout << "Not a valid option" << endl;

	}
	else if (month == 2 && day > 28 && year % 4 != 0) {

		cout << "Not a valid option" << endl;

	} else if (month == 2 && day > 29 && year % 4 == 0) {

		cout << "Not a valid option" << endl;

	} else {

		yearAlpha = getAlpha(year);
		alphaArrayIndex = yearAlpha - 'A';
		numMonth = numArray[alphaArrayIndex][month - 1];

		cout << str << " " << dayArray[(day + numMonth - 1) % 7] << endl;

	}	

}

char calender::getAlpha(int year) {

	ifstream in("../calender.txt");

	if (!in) {
		cout << "Cannot open file for reading" << endl;
	}
	do {
		int n = -1;
		char ch = 'z';
		in >> n >> ch;

		if (in.eof()) {
			cout << "Year not found" << endl;
		} else if (n == year) {
			return ch;
			break;
		}


	} while (1);


}