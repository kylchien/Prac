#include <iostream>
#include <random>
using namespace std;

/*
konwledge for modulo in bit operation
x % 2 inpower n == x & (2 inpower n - 1).
x % 2 == x & 1
x % 4 == x & 3
x % 8 == x & 7

You have an array with all the numbers from 1 to N, where N is at most 32,000. The
array may have duplicate entries and you do not know what N is. With only 4KB of
memory available, how would you print all duplicate elements in the array?

We have 4KB of memory which means we can address up to 8 * 4 * (2^10) bits. Note that 32*
(2^10) bits is greater than 32000. We can create a bit vector with 32000 bits, where each bit
represents one integer.
NOTE: While this isn¡¦t an especially diffcult problem, it¡¦s important to implement this cleanly.
We will deifine our own bit vector class to hold a large bit vector.
*/

class BitSet 
{
private:
	int* bitset_;

public:
	BitSet(int n)
	{
		bitset_ = new int[n >> 5]{0};  //divided by 32, initialize with 0
	}

	~BitSet()
	{
		if(bitset_)
			delete bitset_;
		bitset_ = nullptr;
	}

	bool get(int pos) {
		int wordNumber = (pos >> 5); // divide by 32
		int bitNumber = (pos & 0x1F); // mod 32
		return (bitset_[wordNumber] & (1 << bitNumber)) != 0;
	}

	void set(int pos) {
		int wordNumber = (pos >> 5); // divide by 32
		int bitNumber = (pos & 0x1F); // mod 32
		bitset_[wordNumber] |= 1 << bitNumber;
	}
};

void checkDuplicates(int* array, int size)
{
	BitSet bs(size);
	for (int i = 0; i < size; ++i) {
		int num = array[i];
		int num0 = num - 1; // bitset starts at 0, numbers start at 1
		if (bs.get(num0))
			cout << num << endl;
		else
			bs.set(num0);
	}
}

void findDuplicateIn4kbMemory()
{
	constexpr int size = 32000;
	int array[size] = { 0 };
	for (int i = 0; i < size; ++i) array[i] = i + 1;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(1, size-1);
	
	for (int i = 0; i < 3; ++i) {
		int index = dist(gen);
		int val = dist(gen);
		array[index] = val;
		cout << "index:" << index << ", val:" << val << endl;
	}

	checkDuplicates(array, size);
	
}



int main()
{
	//findDuplicateIn4kbMemory();
	getchar();
	return 0;
}