#pragma once
#include "../test.h"

/*
anagram:
An anagram is a type of word play, the result of rearranging 
the letters of a word or phrase to produce a new word or phrase, 
using all the original letters exactly once
Example: silent ~ listen
*/

/*
sol1:  return sort(string1) == sort(string2)
*/

//sol2: count unique char; if they are anagram they shall match
bool anagram(char* buf1, char* buf2)
{
	int freq[128] = {0};
	int len1 = 0, len2=0;
	char* copy1 = buf1;
	char* copy2 = buf2;
	while (*copy1) { ++copy1; ++len1; }
	while (*copy2) { ++copy2; ++len2; }
	if (len1 != len2) return false;

	for (int i = 0; i <len1; ++i) {
		int c1 = (int)buf1[i];
		int c2 = (int)buf2[i];
		freq[c1]++;
		freq[c2]--;
	}

	for (int i : freq) {
		if (i != 0) return false;
	}
	return true;
}

void testAnagram()
{
	char buf1[10] = "silent";
	char buf2[10] = "listen";
	bool actual = anagram(buf1, buf2);
	TEST_BOOL(true, actual);

	char buf3[10] = "silent";
	char buf4[10] = "1isten";
	actual = anagram(buf3, buf4);
	TEST_BOOL(false, actual);
}
