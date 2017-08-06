#include "practice.h"

void testbed() {

	/*actice a;
	a.set_name("Santosh");
	a.give_name();
	a.set_age(26);
	a.give_age();
	a.fini();
	*/

	student b;
	b.init("Poojie", 17);
	b.print();
	b.fini();

}

int main() {

	testbed();

	return 0;

}