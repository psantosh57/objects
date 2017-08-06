#include "/util/util.h"

class calender {
	public:
		void compute_day(const char*,int,int,int);
		const char findLetterFromYear(int year);
		int findNumberFromLetterAndMonth(const char letter, int month);
		const char* findDayFromNumberAndDate(int number, int date);

	private:
		bool _validDate(int, int, int);
		int arrStep2[14][12] = {{1,4,4,7,2,5,7,3,6,1,4,6},{2,5,5,1,3,6,1,4,7,2,5,7},{3,6,6,2,4,7,2,5,1,3,6,1},{4,7,7,3,5,1,3,6,2,4,7,2},{5,1,1,4,6,2,4,7,3,5,1,3},{6,2,2,5,7,3,5,1,4,6,2,4},{7,3,3,6,1,4,6,2,5,7,3,5},{1,4,5,1,3,6,1,4,7,2,5,7},{2,5,6,2,4,7,2,5,1,3,6,1},{3,6,7,3,5,1,3,6,2,4,7,2},{4,7,1,4,6,2,4,7,3,5,1,3},{5,1,2,5,7,3,5,1,4,6,2,4},{6,2,3,6,1,4,6,2,5,7,3,5},{7,3,4,7,2,5,3,6,1,4,6}};
		const char* daysOfTheWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
		const char* monthsOfTheYear[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
};
