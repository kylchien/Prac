#include "stdio.h"
#include <vector>
#include <iostream>

#include "MyString.h"
#include "RemoveDuplicateChar.h"
#include "Anagram.h"
#include "Replace.h"
#include "LongestSubstr.h"
#include "LongestPalindromicSubstr.h"
#include "../test.h"

using namespace std;


int main()
{
	//test_itoa();
	//test_atoi();
	//testReverseWords();
	//testReverse();
	//testRemoveDuplicateChar();
	//testAnagram();
	//testReplace();
	
	//testlengthOfLongestSubstring();

	testLongestPalindrome();
	

	getchar();
	return 0;
}


/*
anagram:
An anagram is a type of word play, the result of rearranging 
the letters of a word or phrase to produce a new word or phrase, 
using all the original letters exactly once
Example: silent ~ listen

A palindrome is a word, phrase, number, or other sequence of characters 
which reads the same backward or forward. Allowances may be made for 
adjustments to capital letters, punctuation, and word dividers.
Example: "Amor, Roma"
*/