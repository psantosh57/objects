#include "temperature.h"

void testbed() {

	temperature a;
	bool ifTempMatch = false;
	double tempMatch = 0.0;

	for (int i = -50; i <= 50; i += 5) {

		double centigrade = a.fToC(i);

		double farenheit = a.cToF(centigrade);


		if (centigrade == farenheit) {			
			ifTempMatch = true;
			tempMatch = centigrade;
		}

	}

	if (ifTempMatch) {
		cout << "Centigrade and Farenheit temperatures match at " << tempMatch << endl;
	}

}

int main() {

	testbed();

	return 0;

}