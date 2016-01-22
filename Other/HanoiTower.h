#pragma once
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

class HanoiTower 
{
private:	
	stack<int> disks;
	int index;

public:
	HanoiTower(int i) :index(i) {  }
	
	~HanoiTower() {}

	//int getIndex() const { return index;}
	
	void add(int d) 
	{
		if (!disks.empty() && disks.top() <= d) {
			cerr << "Error placing disk " << d << " to tower " << index << endl;
		}
		else disks.push(d);
	}
	
	void moveTopTo(HanoiTower& t) 
	{
		if (disks.empty())
			cerr << "Error: no disk in tower " << index << endl;
		int top = disks.top();
		t.add(top);
		cout << "Move disk " << top << " from tower " << index << " to tower " << t.index << endl;
		disks.pop();
	}
	
	void print() 
	{
		cout << "Contents of tower " << index << ":";
		stack<int> tmp;
		while (!disks.empty()) {
			int top = disks.top();
			cout << top << " ";
			tmp.push(top);
			disks.pop();
		}
		while (!tmp.empty()) {
			int top = tmp.top();
			disks.push(top);
			tmp.pop();
		}
	}
	
	void moveDisks(int n, HanoiTower& destination, HanoiTower& buffer)
	{
		if (n > 0) {
			moveDisks(n - 1, buffer, destination);
			moveTopTo(destination);
			buffer.moveDisks(n - 1, destination, *this);
		}
	}
};


void testHanoiTower(int n)
{
	HanoiTower* towers[3]; 
	for (int i = 0; i < 3; ++i)
		towers[i] = new HanoiTower(i + 1);

	for (int i = n; i >= 1; --i) towers[0]->add(i);

	towers[0]->moveDisks(n, *towers[2], *towers[1]);

	for (int i = 0; i < 3; ++i)
		delete towers[i]; 

}