
#include "temperature.h"

//Function to convert Farenheit to Centigrade
double temperature::fToC(double tempInF) {

	double tempInC = ((5.0 / 9)*(tempInF - 32));

	cout << tempInF << " F = " << tempInC << " C"<<endl;

	return tempInC;

}

//Function to convert Centigrade to Farenheit
double temperature::cToF(double tempInC) {

	double tempInF = ((9.0 * tempInC / 5) + 32);

	cout << tempInC << " C = " << tempInF << " F"<<endl;

	return tempInF;

}

