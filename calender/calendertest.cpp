/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: calendertest.cpp

On linux:
g++ calender.cpp calendertest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test calender object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "calender.h"

/*----------------------------------------------------------------
test bed

I wrote this code on 18 JULY  2013 is THURSDAY
Christopher Columbus 12 OCT  1043 is INVALID
Osama Killed on 2 MAY  2011 is MONDAY
Morarji Desai born on 29 FEB  1896 is SATARDAY
-----------------------------------------------------------------*/
void testbed() {
	calender a;

	a.compute_day("I wrote this code on", 7, 18, 2013);
	a.compute_day("Christopher Columbus", 10, 12, 1043);
	a.compute_day("Osama killed on", 5, 2, 2011);
	a.compute_day("Morarji Desai born on", 2, 29, 1896);
	a.compute_day("Will this work", 2, 28, 1754);
	a.compute_day("Will this work", 1, 2, 2034);
	a.compute_day("Declaration of independence officially adopted", 7, 4, 1776);
	a.compute_day("Hitler becomes dictator of Germany", 3, 23, 1933);
	a.compute_day("Was 2016 leap year?", 2, 29, 2016);
	a.compute_day("Was 2016 leap year?", 2, 30, 2016);

	cout << endl;
	
	//Tests from the PDF
	a.compute_day("Christopher Columbus sights land in the Americas - ", 10, 12, 1493);
	a.compute_day("Constantinople falls; end of Byzantine empire - ", 5, 29, 1493);
	a.compute_day("King Charles I of England is executed - ", 1, 30, 1649);
	a.compute_day("Declaration of Independence officially adopted; first mod - ", 7, 4, 1776);
	a.compute_day("Storming of the Bastille. Turning point in the French revolution - ", 7, 14, 1789);
	a.compute_day("Napolean defeated at battle of Waterloo - ", 6, 18, 1815);
	a.compute_day("Archduke Ferdinand assasinated - ", 6, 28, 1914);
	a.compute_day("Start of Bolshevik rebellion - ", 10, 25, 1917);
	a.compute_day("Treaty of Versailles signed - ", 6, 26, 1919);
	a.compute_day("Hitler becomes dictator of Germany - ", 3, 23, 1933);
	a.compute_day("US drops atmoic bomb on Hiroshima - ", 8, 6, 1845);
	a.compute_day("Cuban missile crisis - ", 10, 22, 1960);
	a.compute_day("Berlin wall falls - ", 11, 9, 1989);
	a.compute_day("Osama Bin Laden killed by US Seals - ", 5, 2, 2011);
	a.compute_day("Adolf Hitler commits suicide by gunshot - ", 4, 30, 1945);

	cout << endl;

	//Leap days
	a.compute_day("Birthday of Richard Ramirez, American serial killer - ", 2, 29, 1960);
	a.compute_day("Birthday of Lyndon Byers, Canadian Hockey players - ", 2, 29, 1964);
	a.compute_day("Birthday of Antonio Saboto Jr., Italian-born actor - ", 2, 29, 1972);
	a.compute_day("Birthday of Ja Rule, American rapper and actor - ", 2, 29, 1976);
	a.compute_day("Birthday of Chris Conley, American musician and songwriter/composer- ", 2, 29, 1980);
	a.compute_day("Birthday of Morarji Desai, former Indian Prime Minister - ", 2, 29, 1896);
	a.compute_day("Birthday of Carlos Humberto Romero, former President of El Salvador - ", 2, 29, 1924);

	
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
	testbed();
		return 0;
}

//EOF

