#pragma once
#include "../test.h"


bool isMatch(char* str, const char* pattern)
{
	if (str == nullptr || pattern == nullptr) 
		return false;
	while (*pattern)
		if (!*str || *str++ != *pattern++)
			return false;
	return true;
}

size_t length(const char* str)
{
	size_t len = 0;
	while (*str) {
		++str;
		len++;
	}
	return len;
}

//assume src will be allocated with sufficient space
//in-place, but with extra memory
void replace(const char* pattern, const char* tgt, char* src)
{
	if (!src || !pattern|| !tgt ) 
		return;

	int pattern_len = length(pattern);
	int src_len = length(src);
	int tgt_len = length(tgt);

	char* scan = src;
	int count = 0;

	//scan 1st time to get the occurrence
	while (*scan) {
		if (isMatch(scan, pattern)) {
			count++;
			scan += pattern_len;
		}
		else scan++;
	}
	
	int new_len = src_len + count *(tgt_len - pattern_len);
	char* buf = new char[new_len+1] {'\0'};
	char* bufptr = buf;
	scan = src;

	//fill the buffer properly
	while (*scan) {
		if (isMatch(scan, pattern)) {
			const char* tgt_copy = tgt;
			while (*tgt_copy) *bufptr++ = *tgt_copy++;
			scan += pattern_len;
		}
		else *bufptr++ = *scan++;
	}

	//copy back to src
	scan = src;
	bufptr = buf;
	while (*bufptr) *scan++ = *bufptr++;
	
	*scan = '\0';
	delete buf;
}

void testReplaceHelper(const char* p, const char* t, const char* s, char* result)
{
	char* tmp;

	char* pattern = new char[strlen(p) + 1];
	pattern[strlen(p)] = '\0';
	tmp = pattern;
	while (*p) *pattern++ = *p++;
	pattern = tmp;

	char* target = new char[strlen(t) + 1];
	target[strlen(t)] = '\0';
	tmp = target;
	while (*t) *target++ = *t++;
	target = tmp;

	char* src = new char[100]{ '\0' };
	tmp = src;
	while (*s) *src++ = *s++;
	src = tmp;
	cout << src << endl;
	replace(pattern, target, src);

	memcpy(result, src, strlen(src) + 1);

	delete[] pattern;
	delete[] target;
	delete[] src;
}

void testReplace()
{
	char result[100];
	testReplaceHelper("abc", "x", "abcabc", result);
	TEST_C_STR("xx", result);

	testReplaceHelper("aa", "x", "abaaaaabc", result);
	TEST_C_STR("abxxabc", result);

	testReplaceHelper("aa", "", "abaaaaabc", result);
	TEST_C_STR("ababc", result)

		testReplaceHelper("a", "bb", "abcabc", result);
	TEST_C_STR("bbbcbbbc", result)

		testReplaceHelper("abcabc", "ya", "abcabc", result);
	TEST_C_STR("ya", result)
}
