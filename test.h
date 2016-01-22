#pragma once

#include <assert.h>
#include <iostream>
#include <sstream>
#include <string.h>

using std::cout;
using std::endl;
using std::ostringstream;

#define TEST_C_STR(e, a) \
	test_c_str(e,a,__LINE__, __FILE__);

#define TEST_BOOL(e, a) \
	test<bool>(e, a, false, 0, __LINE__, __FILE__)

#define TEST_INT(e, a) 	\
	test<int>(e, a, false, 0, __LINE__, __FILE__)

#define TEST_DOUBLE(e, a, d) \
	test<double>(e, a, true, d, __LINE__, __FILE__)


#define OSS_PREFIX(condition, oss, fail) \
	if(condition) \
		oss << "[pass] "; \
	else { \
		oss << "[fail] "; \
		fail = true; \
	} \

template<typename T>
void test(T expect, T actual, bool useDelta, T delta, int lineNum, char* fileName) 
{
	ostringstream oss;
	bool fail = false;

	if(useDelta){
		auto diff = (T)(expect - actual);
		diff = (diff < 0)? -diff:diff;
		OSS_PREFIX(diff < delta, oss, fail);
	}
	else {
		OSS_PREFIX(expect == actual, oss, fail);
	}
	
	if (fail) {
		cout << "\nLine " << lineNum << ", file \"" << fileName << "\":" << endl;
	}
	oss << "expect:" << (T)expect << ", actual:" << (T)actual;
	if (useDelta) oss << ", delta:" << delta;
	cout << oss.str() << endl;

	//if (fail) assert(false);
}

void test_c_str(const char* e, const char* a, int lineNum, char* fileName)
{
	ostringstream oss;
	bool fail = false;

	OSS_PREFIX(strcmp(e, a) == 0, oss, fail);
	
	if (fail) {
		cout << "\nLine " << lineNum << ", file \"" << fileName << "\":" << endl;
	}
	oss << "expect:" << e << ", actual:" << a;
	cout << oss.str() << endl;

	//if (fail) assert(false);
}