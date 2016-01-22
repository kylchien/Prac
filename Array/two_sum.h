#pragma once
#ifndef TWO_SUM_H
#define TWO_SUM_H

#include <vector>
#include <map>

using std::vector;
using std::map;

/*
example: array contains 5 elements

{5 4 -1 3 2}

find the indices whose sum of two elements are equal to 1

sol: (2, 4)   -1 + 2 = 1

none found returns (-1, -1)

since its two-sum, we only need to track one of the number,
the other complement nubmer when we visit we can return both of them at once
key: using hash or map to get O(1) check time
overall runtime ins O(n)

hash stores:
hash[-4] = 0
hash[-3] = 1
hash[2] = 2   <= hit
hash[-2] = 3
*/

vector<int> two_sum(vector<int>& array, int target)
{
	vector<int> sol = {-1, -1};
	map<int, int> hash;
	for (int i = 0; i < array.size(); ++i) {
		map<int, int>::iterator iter = hash.find(array[i]);
		if (iter == hash.end()) {
			hash[target - array[i]] = i;
		}
		else {
			sol[0] = iter->second;
			sol[1] = i;
			break;
		}
	}
	return sol;
}


#endif

