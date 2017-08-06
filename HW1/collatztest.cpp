#include "collatz.h"

void testbed() {

	collatz a;
	cout << "Collatz for 11" << endl;
	a.collatzConjecture(11,1);
	cout << "Collatz for 27" << endl;
	a.collatzConjecture(27,1);

}

int main() {

	testbed();

	return 0;
}