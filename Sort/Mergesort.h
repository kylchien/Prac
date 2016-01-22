#pragma once
#include <iostream>
#include <vector>
using namespace std;
void merge(int*, int*, int, int, int);

/*
in-place sort is possible but not easy to implement;
better to use auxiliary space
*/

void mergesort(int* array, int* copy, int start, int end)
{
	if (array == nullptr) return;
	if (end == start) return;

	int mid = start + (end - start) / 2;
	mergesort(array, copy, start, mid);
	mergesort(array, copy, mid + 1, end);
	merge(array, copy, start, mid, end);

	//copy back
	for (int i = start; i <= end; ++i)
		array[i] = copy[i];
}

/*
merge left portion(start - mid) and right portion(mid+1 - end)
three conditions:

1. 1st element in the left is smaller than right's 1st element
2. right is empty
3. left cursor is no more than index mid

*/
void merge(int* array, int* copy, int start, int mid, int end)
{
	int left = start, right = mid + 1;

	for (int i = start; i <= end; ++i) {
		if ((array[left] < array[right] || right>end) && left <= mid) {
			copy[i] = array[left];
			left++;
		}
		else {
			copy[i] = array[right];
			right++;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////

void merge(vector<int>& v, int st, int mid, int ed, vector<int>& aux)
{
	int left = st, right = mid + 1;
	for (int i = st; i <= ed; ++i) {
		if (left <= mid && (right > ed || v[left] < v[right]))	//order matters if we use vector; 
			aux[i] = v[left++];									//assure it will not access out-of-range
		else 
			aux[i] = v[right++];
	}
	for (int i = st; i <= ed; ++i)
		v[i] = aux[i];
}



void mergeSortUtil(vector<int>& v, int st, int ed, vector<int>& aux)
{
	if (st == ed) return;
	int mid = st + (ed-st) / 2;
	mergeSortUtil(v, st, mid, aux);
	mergeSortUtil(v, mid + 1, ed, aux);
	merge(v, st, mid, ed, aux);
}

void mergeSort(vector<int>& v)
{
	int n = v.size();
	if (n <= 1) return;
	vector<int> aux(n,0);
	mergeSortUtil(v, 0, n-1, aux);
}


void testMergesort()
{
	int array[9] = { 7, 5, 5, 4, 6, 1, 2, 1, 3 };
	int copy[9];

	mergesort(array, copy, 0, 8);

	for (auto i : array)
		cout << i << ", ";
	cout << endl;

	int array1[3] = { -1,-1,-1 };
	mergesort(array1, copy, 0, 2);

	for (auto i : array1)
		cout << i << ", ";
}

void testMergesort2()
{
	vector<int> v = {1,3,5,7,9,2,4,6,8,0};
	mergeSort(v);
	for (auto i : v)
		cout << i << " ";
	cout << endl;

	vector<int> v1 = { 1,1,0 };
	mergeSort(v1);
	for (auto i : v1)
		cout << i << " ";
	cout << endl;
}