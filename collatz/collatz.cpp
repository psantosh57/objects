#include "collatz.h"

void collatz::collatzConjecture(int n, int step) {
	
	if (n == 1) {
		cout << n << " - Step " << step << endl;
	}
	else {
		cout << n << " - Step " << step << endl;
		step++;

		if (n % 2 == 0) {
			n /= 2;
			collatzConjecture(n, step);
		}
		else {
			n = ((3 * n) + 1);
			collatzConjecture(n, step);
		}
	}	
}