#include <iostream>
#include "BitSwapRequired.h"
#include "CountNumOne.h"

#include "../test.h"
#include <iostream>
#include <bitset>


using namespace std;

int main()
{
	//testBitSwapRequired();
	testCountNumOne();

	getchar();
	return 0;
}

/*
* any number '&' 1 can get the least significant bit
* n&(n-1) always eliminates the least significant 1.
* if n is power of 2, x%n = x&(n-1)
*/