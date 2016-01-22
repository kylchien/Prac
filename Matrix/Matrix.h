#pragma once
#include <iostream>
#include <iomanip> 

using std::cout;
using std::endl;
using std::setfill;
using std::setw;

int** allocMatrix(int n)
{
	int** matrix = new int*[n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new int[n];
	}
	return matrix;
}

void deallocMatrix(int** mat, int n)
{
	for (int i = 0; i < n; ++i) {
		int* temp = mat[i];
		delete[] temp;
	}
	delete[] mat;
}

void printMatrix(int** mat, int r, int c)
{
	int buf = 1;
	if (r*c >= 10 && r*c < 100) buf=2;
	if (r*c >= 100 && r*c < 1000) buf = 3;

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cout << setfill(' ') << setw(buf) << mat[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}