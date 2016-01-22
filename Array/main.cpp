#include <iostream>
#include "two_sum.h"
#include "three_sum.h"
#include "CommonElementsInSortedArray.h"
#include "../test.h"

#include <random>


using namespace std;

void test_three_sum()
{
	vector<int>  array = { -1,1,0,2,4,3,5,-3,-2,-2,-1};
	auto sol = three_sum(array,8);
	for (auto s : sol) {
		cout << s << "\n";
	}
}


void test_two_sum()
{
	constexpr int num_test = 100;
	for (int i = 0; i < num_test; ++i) {
		random_device rd;
		mt19937 gen(rd());

		uniform_int_distribution<> dist(-100, 100);

		vector<int> array;

		for (int n = 0; n<10; ++n)
			array.push_back( dist(gen) );

		uniform_int_distribution<> dist2(0, 9);

		int index1 = dist2(gen);
		int index2 = dist2(gen);
		while(index2 == index1) index2 = dist2(gen);

		int target = array[index1] + array[index2];

		auto sol = two_sum(array, target);

		TEST_INT(target, array[sol[0]] + array[sol[1]]);
	}
}


int main()
{
	//test_two_sum();
	//test_three_sum();
	testCommonElements();

	getchar();
	return 0;
}



