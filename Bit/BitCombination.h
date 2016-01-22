#pragma once
#include <iostream>
using std::cout;
using std::endl;

/*
print all combinations given n bits, for example:
n = 0, 0
n = 1, 0, 1
n = 2, 00, 01, 10, 11

key: any number '&' 1 can get the least significant bit

2^n (for loop) x lg(n)(each n bit)
O( 2^n lg(n) )
*/

void bitCombination(int n)
{
	if (n == 0)
		cout << '0' << endl;

	int len = 1;
	for (int i = 0; i < n; ++i) len *= 2;

	char* buf = new char[n + 1];
	buf[n] = '\0';

	//reversly fill up buf (from least significant bit)
	for (int i = 0; i < len; ++i) {
		int num = i;
		int index = n - 1;
		do {
			buf[index--] = (num & 1) + '0';
			num >>= 1;
		} while (index >= 0);
		cout << buf << endl;
	}
	delete buf;
}