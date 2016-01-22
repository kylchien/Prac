#pragma once
#include <iostream>
#include <bitset>

using namespace std;

//Please note the fact that: n&(n-1) always eliminates the least significant 1. 

int countNumOne(int n)
{
	int count = 0;
	while (n != 0) {
		n = n&(n - 1);
		bitset<16> bs(n);
		cout << bs << " => " << n << endl;
		count++;
	}
	return count;
}

void testCountNumOne()
{
	int n = 15;
	bitset<16> bs(n);

	cout << "original:" << bs << endl;
	cout << "ans is " << countNumOne(n) << endl;
}