#include "calender.h"

bool calender::_validDate(int month, int date, int year) {
	//Valid year range
	if ( year < 1755 || year > 2033) {
		return false;
	}

	//Leap year
	if ( month == 2 ) {
		
		//Invalid
		if (date > 29) {
			return false;
		}
		
		if (year%4 != 0 && date > 28) {
			return false;
		} else {
			//Leap year
			return true;
		}
	}

	//30 days
	if (date > 30 && ( month == 4 || month == 6 || month == 9 || month == 11)) {
		return false;
	}

	return true;
}

void calender::compute_day(const char* string, int month, int date, int year) {

	bool validDate = _validDate(month, date, year);
	const char *day = "INVALID";
	
	if (validDate) {
		const char letter = findLetterFromYear(year);
		int number = findNumberFromLetterAndMonth(letter, month);
		day = findDayFromNumberAndDate(number, date);
	}	

	cout << string << " " << date << " " << monthsOfTheYear[month-1] << " " << year << " is " << day << endl;
}

const char calender::findLetterFromYear(int year) {
	ifstream in("./input.dat");

	if (!in) {
		cout << "Cannot open input.dat for reading" << endl;
	}

	do {
		int refYear = 0;
		char letter = 'Z';

		in >> refYear >> letter;
		if (!in.eof()) {
			if ( refYear == year) {
				return letter;
			}
		} else {
			return 'Z';
		}
	} while(1);
}

int calender::findNumberFromLetterAndMonth(const char letter, int month) {
	if (letter == 'Z') {
		return -1;
	}

	int letterNum = letter - 'A';
	return arrStep2[letterNum][month-1];
}

const char *calender::findDayFromNumberAndDate(int number, int date) {
	if (number == -1) { return "INVALID"; }
	//Use the number and date to find Day. Offset the date based on the number.
	return daysOfTheWeek[(number-1+date-1)%7];
}

