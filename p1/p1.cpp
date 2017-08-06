#include "p1.h"

//Function to calculate power
int p1::calcPower(int base, int expo) {

	int result = base;

	for (int j = 1; j < expo; j++) {
		result *= base;
	}

	return result;

}

//Function to calculate number of digits in given number which will in turn tell us how many spaces to insert
int p1::calcSpaces(int n, int count) {
	
	int mod = n % 10;
	n = n / 10;

	if (n == 0 && mod != 0) {
		return count;
	}
	else if (n == 1) {
		count++;
		return count;
	}
	else if (n > 1) {
		count++;
		calcSpaces(n, count);
	}

}

int p1::calc_n_2(int n) {

	return  n*n;

}

int p1::calc_n_3(int n) {

	return n*n*n;

}

int p1::calc_2_n(int n) {

	if (n == 0) {

		return 1;
	}
	else {

		int result = 2;

		for (int j = 1; j < n; j++) {

			result *= 2;

		}

		return result;

	}
	

}

void p1::a1() {

	cout << "a1" << endl << endl;

	for (int i = 1; i < 7; i++) {

		for (int j = 1; j <= i; j++) {
			cout << j;
		}

		cout << endl;

	}

}

void p1::a2() {

	cout << "a2" << endl << endl;

	for (int i = 1; i < 7; i++) {
		
		int j = 6;
		int k = 0;

		for (j = (6-i); j >= 0; j--) {

			cout << " ";
		}
		
		for (k = i; k > 0; k--) {

			cout << k;
		}
		
		cout << endl;
	}
	
}

void p1::a3() {

	cout << "a3" << endl << endl;

	for (int i = 1; i < 7; i++) {

		for (int j = 1; j <= (7-i); j++) {

			cout << j;

		}

		cout << endl;

	}


}

void p1::a4() {

	cout << "a4" << endl << endl;

	for (int i = 1; i < 7; i++) {

		for (int j = 0; j < i; j++) {

			cout << " ";
		}

		for (int k = 1; k <= (7-i); k++) {

			cout << k;
		}

		cout << endl;
	}

}

void p1::a_power_b() {

	cout << "a_power_b" << endl << endl;

	cout << "a b\t  a^b" << endl;

	for (int base = 1; base < 8; base++) {

		int expo = (base + 1);

		int power = calcPower(base, expo);
		int spaces = calcSpaces(power, 1);
		cout << base << " " << expo;
		//Subtracting from 11 as "\t  " is 10 spaces and 1 more to align units place under b
		for (int i = 1; i < (11-spaces); i++) {
			cout << " ";
		}
		cout << power << endl;

	}

}

void p1::print_n_n2_n3() {
	
	cout << "print_n_n2_n3" << endl << endl;

	cout << "n n^2 n^3"<< endl;
	for (int i = 1; i < 10; i++) {
		int pow_n_2 = calc_n_2(i);
		int numSpaces_n_2 = calcSpaces(pow_n_2, 1);
		int pow_n_3 = calc_n_3(i);
		int numSpaces_n_3 = calcSpaces(pow_n_3, 1);
		cout << i;
		for (int j = 1; j < (5 - numSpaces_n_2); j++) {
			cout << " ";
		}
		cout << pow_n_2;
		for (int j = 1; j < (5 - numSpaces_n_3); j++) {
			cout << " ";
		}
		cout << pow_n_3 << endl;
		

	}

}

void p1::two_power_n() {

	cout << "two_power_n" << endl << endl;

	cout << "n\t2^n" << endl;

	for (int i = 1; i < 20; i++) {

		int ans = calc_2_n(i);
		cout << i;
		int numSpaces = calcSpaces(ans, 1);
		for (int k = 1; k < (11 - numSpaces); k++) {

			cout << " ";
		}
		cout << ans << endl;

	}


}

void p1::print_usa() {

	cout << "print_usa" << endl << endl;

	char arr_u[10][9] = {

		{ 'x','x','x',' ',' ',' ','x','x','x' },
		{' ', 'x', ' ', ' ', ' ', ' ', ' ', 'x'},
		{ ' ', 'x', ' ', ' ', ' ', ' ', ' ', 'x' },
		{ ' ', 'x', ' ', ' ', ' ', ' ', ' ', 'x' },
		{ ' ', 'x', ' ', ' ', ' ', ' ', ' ', 'x' },
		{ ' ', 'x', ' ', ' ', ' ', ' ', ' ', 'x' },
		{ ' ', 'x', ' ', ' ', ' ', ' ', ' ', 'x' },
		{ ' ', 'x', ' ', ' ', ' ', ' ', ' ', 'x' },
		{ ' ','x','x',' ',' ',' ','x','x',' ' },
		{ ' ',' ',' ','x','x','x',' ',' ',' ' }
	};

	char arr_s[10][9] = {

		{ ' ',' ','x','x','x','x',' ','x',' ' },
		{ ' ','x',' ',' ',' ',' ','x','x',' ' },
		{ ' ','x',' ',' ',' ',' ',' ','x',' ' },
		{ ' ','x',' ',' ',' ',' ',' ',' ',' ' },
		{ ' ',' ','x','x','x',' ',' ',' ',' ' },
		{ ' ',' ',' ',' ',' ','x','x',' ',' ' },
		{ ' ',' ',' ',' ',' ',' ',' ','x',' ' },
		{ ' ','x',' ',' ',' ',' ',' ','x',' ' },
		{ ' ','x','x',' ',' ',' ',' ','x',' ' },
		{ ' ','x',' ','x','x','x','x',' ',' '}

	};

	char arr_a[10][9] = {

		{ ' ',' ','x','x','x',' ',' ',' ',' ' },
		{ ' ', ' ',' ',' ','x',' ',' ',' ',' '},
		{ ' ',' ',' ','x',' ','x',' ',' ',' ' },
		{ ' ',' ',' ','x',' ','x',' ',' ',' ' },
		{ ' ',' ','x',' ',' ',' ','x',' ',' ' },
		{ ' ',' ','x',' ',' ',' ','x',' ',' ' },
		{ ' ',' ','x','x','x','x','x',' ',' ' },
		{ ' ','x',' ',' ',' ',' ',' ','x',' ' },
		{ ' ','x',' ',' ',' ',' ',' ','x',' ' },
		{'x','x','x',' ',' ',' ','x','x','x' }


	};

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 9; j++) {

			cout << arr_u[i][j];
		}

		for (int k = 0; k < 9; k++) {

			cout << arr_s[i][k];
		}

		for (int l = 0; l < 9; l++) {

			cout << arr_a[i][l];
		}

		cout << endl;

	}



}
