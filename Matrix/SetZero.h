#pragma once

#include "Matrix.h"
#include "../test.h"

/*
Write an algorithm such that if an element in an MxN matrix is 0,
its entire row and column is set to 0

At first glance, this problem seems easy: just iterate through the matrix
and every time we see a 0, set that row and column to 0. There¡¦s one problem
with that solution though: we will ¡§recognize¡¨ those 0s later on in our iteration
and then set their row and column to zero.Pretty soon, our entire matrix is 0s!

One way around this is to keep a second matrix which "flags the 0 locations".
We would then do a second pass through the matrix to set the zeros.This would
take O(MN) space. Do we really need O(MN) space ? No. Since we¡¦re going to set
the entire row and column to zero, do we really need to track which cell in a
row is zero ? No. We only need to know that row 2, for example, has a zero.

The code below implement this algorithm. We keep track in two arrays all the rows
with zeros and all the columns with zeros. We then make a second pass of the matrix
and set a cell to zero if its row or column is zero.
*/


// m is numRows, n is numCols
void setZero(int** matrix, int m, int n)
{
	int* trackRow = new int[m] {0};
	int* trackCol = new int[n] {0};

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 0) {
				trackRow[i] = 1;
				trackRow[j] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (trackRow[i] == 1 || trackRow[j] == 1) {
				matrix[i][j] = 0;
			}
		}
	}

}


void testSetZeros(int n)
{
	int ** mat = allocMatrix(n);
	int count = 1;
	for (int i = 0; i < n;i++)
		for (int j = 0; j < n;j++)
			mat[i][j] = count++;

	mat[0][0] = 0;
	mat[n / 2][n / 2] = 0;

	printMatrix(mat, n, n);

	setZero(mat, n, n);
	printMatrix(mat, n, n);
}