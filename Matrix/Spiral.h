#pragma once
#include "Matrix.h"
#include "../test.h"

/*
given n print out n^2 in spiral form

1

1 2
4 3

1 2 3
8 9 4
7 6 5

*/

void fillBoundary(int** mat, int n, int row, int col, int& startNum)
{
	if (n == 1) {
		mat[row][col] = startNum;
		return;
	}

	for (int i = 0; i < n - 1; ++i)
		mat[row][col + i] = startNum++;

	for (int i = 0; i < n - 1; ++i)
		mat[row + i][col + n - 1] = startNum++;

	for (int i = n - 1; i > 0; --i)
		mat[row + n - 1][col + i] = startNum++;

	for (int i = n - 1; i > 0; --i)
		mat[row + i][col] = startNum++;
}

void SpiralMatrix(int n)
{
	int** matrix = allocMatrix(n);

	int startNum = 1;
	int startRow = 0;
	int startCol = 0;

	for (int i = n; i > 0; i -= 2) {
		fillBoundary(matrix, i, startRow, startCol, startNum);
		startRow++;
		startCol++;
	}

	printMatrix(matrix, n, n);

	deallocMatrix(matrix, n);

}
