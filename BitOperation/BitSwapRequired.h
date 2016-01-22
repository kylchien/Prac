#pragma once
#include "../test.h"
#include <iostream>
#include <bitset>

using namespace std;
/*
Write a function to determine the number of bits required to convert integer A to
integer B.
Input: 31, 14
Output : 2

This seemingly complex problem is actually rather straightforward.To approach this, ask
yourself how you would !gure out which bits in two numbers are different.
Simple: with an xor.
Each 1 in the xor will represent one different bit between A and B.We then simply need to
count the number of bits that are 1.

*/

int bitSwapRequired(int a, int b) {
	int count = 0;
	for (int c = a ^ b; c != 0; c = c >> 1) {
		count += c & 1;	
	}
	return count;
}



/*
Write a program to swap odd and even bits in an integer with as few instructions as
possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc).

Mask all odd bits with 10101010 in binary (which is 0xAA), then shift them left to put them in
the even bits. Then, perform a similar operation for even bits. This takes a total 5 instructions.

101010101010 0xaa
010101010101 0x55
*/
int swapOddEvenBits(int x) {
	return (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
}


void testBitSwapRequired()
{
	int actual = bitSwapRequired(14, 31);
	TEST_INT(2,actual);

	actual = bitSwapRequired(1, 0);
	TEST_INT(1, actual);
}