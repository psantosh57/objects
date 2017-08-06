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
  calender a ;
  a.compute_day("I wrote this code on",7,18,2013) ;
  a.compute_day("Christopher Columbus",10,12,1043) ;
  a.compute_day("Osama Killed on",5,2,2011) ;
  a.compute_day("Morarji Desai born on",2,29,1896) ;
  a.compute_day("Will this work", 2, 28, 1754);
  a.compute_day("Will this work", 1, 2, 2034);
  a.compute_day("Declaration of independence officially adopted", 7, 4, 1776);
  a.compute_day("Hitler becomes dictator of Germany", 3, 23, 1933);
  a.compute_day("Was 2016 leap year?", 2, 29, 2016);
  a.compute_day("Was 2016 leap year?", 2, 30, 2016);
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  testbed() ;
  return 0 ;
}

//EOF
