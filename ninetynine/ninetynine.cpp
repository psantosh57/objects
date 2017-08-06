#include "ninetynine.h"

void ninetynine::displayPoem() {

	char* tensArr[] = { "Twenty", "Thirty","Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
	char* unitsArr[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
	
	for (int i = 99; i >= 1; i--) {

		int d = i / 10;
		int m = i % 10;
		if (i <= 19 && i >= 0) {

			if (i == 1) {
				cout << unitsArr[i] << " bottle of beer on the wall," << endl;
				cout << endl;
				cout << unitsArr[i] << " bottle of beer on the wall," << endl;
				cout << unitsArr[i] << " bottle of beer" << endl;
				cout << "Take one down, pass it around, " << endl;
				cout << unitsArr[i - 1] << " bottles of beer on the wall" << endl;
				break;

			} else if (i == 19) {
				cout << unitsArr[i] << " bottles of beer on the wall," << endl;
				cout << endl;
				cout << unitsArr[i] << " bottles of beer on the wall," << endl;
				cout << unitsArr[i] << " bottles of beer" << endl;

			} else {
				cout << unitsArr[i] << " bottles of beer on the wall," << endl;
				cout << endl;
				cout << unitsArr[i] << " bottles of beer on the wall," << endl;
				cout << unitsArr[i] << " bottles of beer" << endl;
			}

		} else if (i == 99) {

			cout << tensArr[d - 2] << "-" << unitsArr[m] << " bottles of beer on the wall," << endl;
			cout << tensArr[d - 2] << "-" << unitsArr[m] << " bottles of beer," << endl;
			
		} else if (m != 0) {

			cout << tensArr[d - 2] << "-" << unitsArr[m] << " bottles of beer on the wall" << endl;
			cout << endl;
			cout << tensArr[d - 2] << "-" << unitsArr[m] << " bottles of beer on the wall," << endl;
			cout << tensArr[d - 2] << "-" << unitsArr[m] << " bottles of beer," << endl;

		} else if (m == 0) {
			cout << tensArr[d - 2] << " bottles of beer on the wall" << endl;
			cout << endl;
			cout << tensArr[d - 2] << " bottles of beer on the wall," << endl;
			cout << tensArr[d - 2] << " bottles of beer," << endl;

		} 

		cout << "Take one down, pass it around,"<<endl;
		
	}
}