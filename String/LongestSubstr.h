#pragma once
#include <iostream>
#include <string>
#include <map>
#include "../test.h"

using namespace std;

/*

https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string, find the length of the longest substring without repeating characters. 

abcabcbb => 3 (abc)
bbbbb => 1 (b)
dvdf => 3 (vdf)
abbcdab => 4 (bcda or cdab)

catch: the tricky part is how to reset the start point 
once we encounter a repeatitive char 
*/

int lengthOfLongestSubstring(string s) {
	int n = s.size();
	if (n == 0) return 0;
	if (n == 1)	return 1;

	map<char, int> m;
	int st = 0, ed = 0, max=-1;    //start index, end index, maximum length
	while (ed < n) {
		char c = s[st];
		int nt = st+1;
		while (nt < n && s[nt] == c) {                  //if [a]aab move st to aa[a]b (meet a repeat letter, skip over'em)     
			nt++;
			st++;
		}
		ed = (ed < st) ? st : ed;                       //end shall be always larger or equal to start

		map<char, int>::iterator iter = m.find(s[ed]); 
		if (iter != m.end()){                           //move start index to next non-repeatitive pos (nt)
			nt = iter->second + 1;                      //if only if start is less to nt  
			st = (nt > st)?nt:st;                       //eg abb[c]d[a], when we hit the last a, the nt is 0, but start is 3 already
		}
		m[s[ed]] = ed;
		int len = ed - st + 1;
		max = (max<len) ? len : max;
		ed++;
	}

	return max;
}

/* 
//another sol from Yu's coding garden
//http://yucoding.blogspot.ca/2013/01/leetcode-question-45-longest-substring.html
int lengthOfLongestSubstring2(string s) {
	if(s.size()==0){return 0;}
	if(s.size()==1){return 1;}
	int i=0;
	int j=0;
	int maxl = 0;
	map<char,bool> table;
	while ( (i<s.size()) && (j<s.size()) ){
		if (table[s[j]]==false){
			table[s[j]]=true;
			maxl = max(maxl,j-i+1);
			j++;
		}else if (table[s[j]]==true){
			maxl = max(maxl,j-i);
			table[s[i]]=false;
			i++;
		}
	}
	return maxl;
}
*/

void testlengthOfLongestSubstring()
{
	int len;
	
	len = lengthOfLongestSubstring("aa");
	TEST_INT(1, len);

	len = lengthOfLongestSubstring("ab");
	TEST_INT(2, len);

	len = lengthOfLongestSubstring("abab");
	TEST_INT(2, len);
	
	len = lengthOfLongestSubstring("abba");
	TEST_INT(2, len);
	
	len = lengthOfLongestSubstring("abbba");
	TEST_INT(2, len);
	
	len = lengthOfLongestSubstring("aabc");
	TEST_INT(3, len);
	
	len = lengthOfLongestSubstring("abbca");
	TEST_INT(3, len);
	
	
	len = lengthOfLongestSubstring("tmmzuxt");
	TEST_INT(5,len);

	len = lengthOfLongestSubstring("abbcda");
	TEST_INT(4, len);
}


