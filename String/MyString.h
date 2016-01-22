#pragma once
#include <stdint.h>
#include "../test.h"
/*
Note that this function does not perform overflow check,
and expect the user provide a buffer that allocates sufficient memory.

key: need to check its sign, so we can allocate 1 char beforehand
*/
void my_itoa(int in, char* buf)
{
	int val = in;		//copy of input
	int len = 0;		//string len (no sign)
	int start = 0;		//start position; 0 if positive, 1 if negative

	if (val < 0) {
		val = -val;
		start++;
		buf[0] = '-';
	}

	//assign char in reverse order
	do {
		int quotient = val / 10;
		int digit = val - 10 * quotient;
		buf[start + len++] = (char)((int)'0' + digit);
		val /= 10;
	} while (val > 0);

	buf[start + len] = '\0';

	//swap left and right
	for (int i = 0; i < len / 2; ++i) {
		char temp = buf[start + i];
		buf[start + i] = buf[len + start - 1 - i];
		buf[len + start - 1 - i] = temp;
	}

}

/*
*if minus sign is betwen two consecutive digit sequence, then it is ignored
* Eg 123 - 456 shall return 123456
*
* if consecutive zeros followed by valid digits, it shall omit the zeros and
* return the value of those digits.
*/

int my_atoi(char* str)
{
	bool neg = false;
	char* ptr = str;

	//handling sign
	while (*ptr != '\0' && (*ptr < '0' || *ptr > '9')) {
		if (*ptr == '-') neg ^= (true);
		ptr++;
	}

	int output = 0;
	while (*ptr != '\0') {
		if (*ptr >= '0' && *ptr <= '9') {
			output *= 10;
			output += (int)(*ptr - '0');
		}
		ptr++;
	}

	output = (neg) ? -output : output;
	return output;
}

/*
This is a classic interview question.
The only ¡§gotcha¡¨ is to try to do it IN-PLACE, 
and to be careful for the null character.
*/
void reverse(char *str) 
{
	char * end = str;
	char tmp;
	if (str) {
		//point to last char
		while (*end) {
			++end;
		}
		--end; //back from null terminator
		while (str < end) {
			tmp = *str;
			* str++ = *end;
			* end-- = tmp;
		}
	}
}

void myreverse(char* str)
{
	if (!str) return;
	char* end = str;
	while (*end) end++;
	end--;
	char* start = str;
	while (start < end) {
		char tmp = *start;
		*start++ = *end;
		*end-- = tmp;
	}
}

/*
"one two three" => "three two one"
"one two three " => " three two one"
" one two three" => "three two one "
" one two three " => " three two one "

main idea:
scan from the end of string backwards;
recording each word's start index and index
also save current buff's end index, 
so we know where the next word shall be put into 
*/
void reverseWords(char * src, char * buf)
{
	int size = strlen(src);
	memset(buf, ' ', size);
	if (size == 0) return;
	else if (size == 1) {
		buf[0] = src[0];
		buf[1] = '\0';
		return;
	}

	int start = -1;   //start points to token's first char
	int end = size - 1; //end points to token's last char
	int cur = 0;

	while (end >= 0) {
		while(src[end] == ' ') {
			buf[cur] = ' ';
			end--; cur++;
			if (end < 0) break;
		}

		start = end;
		while (src[--start] != ' ' && start >= 0);
		start++; //start now actually points to another ' ' or -1; need to add it back

		for (int i = 0; i < end - start + 1; ++i) {
			buf[cur++] = src[start + i];
		}

		end = start - 1;
	}

	buf[size] = '\0';
}


void testReverseWords()
{
	char src[20] = "   one two three";
	char tgt[20];
	reverseWords(src, tgt);
	TEST_C_STR("three two one   ", tgt);

	char src1[20] = "one two three";
	reverseWords(src1, tgt);
	TEST_C_STR("three two one", tgt);

	char src2[20] = "one two three  ";
	reverseWords(src2, tgt);
	TEST_C_STR("  three two one", tgt);

	char src3[20] = " one two three  ";
	reverseWords(src3, tgt);
	TEST_C_STR("  three two one ", tgt);
}

void testReverse()
{
	char src[4] = "abc";
	reverse(src);
	TEST_C_STR("cba", src);
}



void test_atoi()
{
	char str[10] = "12345";
	int i = my_atoi(str);
	TEST_INT(12345, i);

	char str1[10] = "-12345";
	i = my_atoi(str1);
	TEST_INT(-12345, i);

	char str2[10] = "+-12345";
	i = my_atoi(str2);
	TEST_INT(-12345, i);

	char str3[10] = "+12345";
	i = my_atoi(str3);
	TEST_INT(12345, i);

	char str4[10] = "+0";
	i = my_atoi(str4);
	TEST_INT(0, i);

	char str5[10] = "-0";
	i = my_atoi(str5);
	TEST_INT(0, i);

	char str6[10] = "-123sd4";
	i = my_atoi(str6);
	TEST_INT(-1234, i);

	char str7[20] = "asd-123sd4";
	i = my_atoi(str7);
	TEST_INT(-1234, i);

	char str8[20] = "-12asd-3sd4";
	i = my_atoi(str8);
	TEST_INT(-1234, i);

	char str9[20] = "-00004";
	i = my_atoi(str9);
	TEST_INT(-4, i);

}


void test_itoa()
{
	int i = 12345;
	char str[10] = "12345";
	my_itoa(i, str);
	TEST_C_STR("12345", str);

	memset(str, 0, sizeof(str));
	i = -137372;
	my_itoa(i, str);
	TEST_C_STR("-137372", str);

	memset(str, 0, sizeof(str));
	i = -0;
	my_itoa(i, str);
	TEST_C_STR("0", str);

	memset(str, 0, sizeof(str));
	int l = -123456;
	my_itoa(l, str);
	TEST_C_STR("-123456", str);
}