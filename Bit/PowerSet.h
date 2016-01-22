#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <math.h>  
#include <map>

using namespace std;

/*
given {x, y ,z} return {} {x} {y} {z} {xy} {xz} {yz} {xyz}
For the whole power set of S we get:
{ } = 000 (Binary) = 0 (Decimal)
{x} = 100 = 4
{y} = 010 = 2
{z} = 001 = 1
{x, y } = 110 = 6
{x, z } = 101 = 5
{y, z } = 011 = 3
{x, y, z } = 111 = 7

map lg(n)
for 2^n * lg (n)
so overall still O(2^n lg (n))

can use & 1<<bitpos to do the same trick 
*/
void powerSet(vector<char>& vec)
{
	int exp = vec.size();
	int len = pow(2, exp);

	map<int, char> map;
	for (int i = 0; i < exp; ++i) {
		map[i + 1] = vec[i];
	}

	string output = "";

	for (int i = 0; i < len; ++i) {
		string s = "{";
		int copy = i;
		int bitpos = 1; //from low pos to high pos (right to left)
		while (copy > 0) {
			if (copy & 1) {
				char c = map[bitpos];
				s += c;
			}
			copy >>= 1;
			bitpos++;
		}
		s += "} ";
		output += s;
	}
	cout << output << endl;
}