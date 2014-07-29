/*
 * main.cpp
 *
 *  Created on: Jul 28, 2014
 *      Author: math4tots
 */
#include <algorithm>
#include <iostream>
using namespace std;

class FixedDiceGameDiv2 {
public:
	double getExpectation(int A, int B) {
		int
			C = min(A,B),
			total = C*A - ((C*(C+1))/2),
			AC = max(A-C,0),
			sum = (C*(2*C-1)*(C-1))/6 + (C*(C-1))/2 + (AC*(AC+1)*C)/2 + (AC)*C*C;
		return ((double)sum)/((double)total);
	}
};
