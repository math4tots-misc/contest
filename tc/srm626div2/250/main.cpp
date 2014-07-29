/*
 * main.cpp
 *
 *  Created on: Jul 28, 2014
 *      Author: math4tots
 */

#include <vector>
#include <iostream>
using namespace std;


class SumOfPower {
public:
	int findSum(vector<int> xs) {
		const int N = xs.size();
		int power = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j <= N; j++) {
				for (int k = i; k < j; k++) {
					power += xs[k];
				}
			}
		}
		return power;
	}
};

int main() {
	cout << "hello world!" << endl;
	return 0;
}
