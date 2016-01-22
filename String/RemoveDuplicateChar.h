#pragma once
#include "../test.h"
#include <iostream>
using namespace std;

/*
Design an algorithm and write code to remove the duplicate characters in a string
without using any additional bu$er. NOTE: One or two additional variables are !ne.
An extra copy of the array is not.

out is allocated with sufficient space
*/
void removeDuplicateChar_auxspace(char* in, char* out)
{
	bool unique[128] = {false};
	char* cur = out;
	while (*in) {
		int pos = (int)(*in);
		if(!unique[pos]){
			unique[pos] = true;
			*cur++ = *in;
		}
		++in;
	}
	*cur = '\0';
}

// O(n^2)
void removeDuplicateChar_inplace(char* str)
{
	int len = 0;
	char* pivot = str;
	while (*pivot) {
		++pivot;
		++len;
	}

	if (len < 2) return;
	
	
	//tail is the last index that all pos before it contains unique char
	//j is used for searching duplicate(always starting from 0 to tail)
	//i is the current index we focus on
	int tail = 1;
	
	for (int i = 1; i < len; ++i) {
		int j;
		for (j = 0; j < tail; ++j) {
			if (str[i] == str[j]) break; //find duplicate; skip to next char
		}
		//str[j] is unique!
		if (j == tail) {
			str[tail] = str[i];
			++tail;	
		}
	}
	str[tail] = '\0';
	

	/*my costly implementation
	pivot = str;
	char* scan;

	while (*pivot) {
		scan = pivot + 1;
		while (*scan) {
			//move the rest of string forward by 1 
			if (*scan == *pivot) {
				char* cur = scan;
				while (*cur) {
					*cur = *(cur + 1);
					++cur;
				}
			}
			//move the scan index to next 1
			else {
				++scan;
			}
		}
		++pivot;
	}*/
}

void testRemoveDuplicateChar()
{
	char src[10] = "ababaaccd";
	char out[10] = { 0 };
	removeDuplicateChar_auxspace(src, out);
	TEST_C_STR("abcd", out);

	char src1[10] = "aa";
	removeDuplicateChar_auxspace(src1, out);
	TEST_C_STR("a", out);

	char src2[10] = "abc";
	removeDuplicateChar_auxspace(src2, out);
	TEST_C_STR("abc", out);

	char src3[10] = "ababaaccd";
	removeDuplicateChar_inplace(src3);
	TEST_C_STR("abcd", src3);

	char src4[10] = "aa";
	removeDuplicateChar_inplace(src4);
	TEST_C_STR("a", src4);

	char src5[10] = "ab";
	removeDuplicateChar_inplace(src5);
	TEST_C_STR("ab", src5);

	char src6[10] = "aab";
	removeDuplicateChar_inplace(src6);
	TEST_C_STR("ab", src6);

	char src7[10] = "acabaabc";
	removeDuplicateChar_inplace(src7);
	TEST_C_STR("acb", src7);

}