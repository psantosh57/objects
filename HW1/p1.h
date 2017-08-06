#pragma once

#ifndef P1_H
#define P1_H

#include "../util/util.h"

class p1 {

public:
	
	void print_usa();
	void a_power_b();
	void print_n_n2_n3();
	void two_power_n();
	void a1();
	void a2();
	void a3();
	void a4();

private:
	int calcPower(int base, int expo);
	int calcSpaces(int n, int cnt);
	int calc_n_2(int n);
	int calc_n_3(int n);
	int calc_2_n(int n);
};

#endif